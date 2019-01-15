<?php
namespace Elastica\Test\Aggregation;

use Elastica\Aggregation\Cardinality;
use Elastica\Document;
use Elastica\Query;
use Elastica\Type\Mapping;

class CardinalityTest extends BaseAggregationTest
{
    protected function _getIndexForTest()
    {
        $index = $this->_createIndex();

        $mapping = new Mapping($index->getType('test'), [
            'color' => [
                'type' => 'keyword',
            ],
        ]);
        $index->getType('test')->setMapping($mapping);

        $index->getType('test')->addDocuments([
            new Document(1, ['color' => 'blue']),
            new Document(2, ['color' => 'blue']),
            new Document(3, ['color' => 'red']),
            new Document(4, ['color' => 'green']),
        ]);

        $index->refresh();

        return $index;
    }

    /**
     * @group functional
     */
    public function testCardinalityAggregation()
    {
        $agg = new Cardinality('cardinality');
        $agg->setField('color');

        $query = new Query();
        $query->addAggregation($agg);
        $results = $this->_getIndexForTest()->search($query)->getAggregation('cardinality');

        $this->assertEquals(3, $results['value']);
    }

    /**
     * @dataProvider invalidPrecisionThresholdProvider
     * @expectedException \InvalidArgumentException
     * @group unit
     *
     * @param $threshold
     */
    public function testInvalidPrecisionThreshold($threshold)
    {
        $agg = new Cardinality('threshold');
        $agg->setPrecisionThreshold($threshold);
    }

    /**
     * @dataProvider validPrecisionThresholdProvider
     * @group unit
     *
     * @param $threshold
     */
    public function testPrecisionThreshold($threshold)
    {
        $agg = new Cardinality('threshold');
        $agg->setPrecisionThreshold($threshold);

        $this->assertNotNull($agg->getParam('precision_threshold'));
        $this->assertInternalType('int', $agg->getParam('precision_threshold'));
    }

    public function invalidPrecisionThresholdProvider()
    {
        return [
            'string' => ['100'],
            'float' => [7.8],
            'boolean' => [true],
            'array' => [[]],
            'object' => [new \StdClass()],
        ];
    }

    public function validPrecisionThresholdProvider()
    {
        return [
            'negative-int' => [-140],
            'zero' => [0],
            'positive-int' => [150],
            'more-than-max' => [40001],
        ];
    }

    /**
     * @dataProvider validRehashProvider
     * @group unit
     *
     * @param bool $rehash
     */
    public function testRehash($rehash)
    {
        $agg = new Cardinality('rehash');
        $agg->setRehash($rehash);

        $this->assertNotNull($agg->getParam('rehash'));
        $this->assertInternalType('boolean', $agg->getParam('rehash'));
    }

    /**
     * @dataProvider invalidRehashProvider
     * @expectedException \InvalidArgumentException
     * @group unit
     *
     * @param mixed $rehash
     */
    public function testInvalidRehash($rehash)
    {
        $agg = new Cardinality('rehash');
        $agg->setRehash($rehash);
    }

    public function invalidRehashProvider()
    {
        return [
            'string' => ['100'],
            'int' => [100],
            'float' => [7.8],
            'array' => [[]],
            'object' => [new \StdClass()],
        ];
    }

    public function validRehashProvider()
    {
        return [
            'true' => [true],
            'false' => [false],
        ];
    }
}
