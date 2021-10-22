#include "map.h"
#include "config.h"

Map::Map()
{
    //初始化加载地图对象
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    //设置地图起始y轴坐标
    m_map1_posY = -GAME_HEIGHT;//第一张图的高度
    m_map2_posY = 0;//第二张图的高度

    //设置地图滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;

}

 //地图滚动坐标计算
void Map::mapPosition()
{
    //处理第一张图片滚动
    m_map1_posY += MAP_SCROLL_SPEED;
    if(m_map1_posY >= 0)//滚动到尽头了，需要重置
    {
        m_map1_posY =-GAME_HEIGHT;
    }

    //处理第二张图片滚动
    m_map2_posY += MAP_SCROLL_SPEED;
    if(m_map2_posY >= GAME_HEIGHT )//大于等于屏幕的高度
    {
        m_map2_posY =0;
    }
}
