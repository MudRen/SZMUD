// Code of ShenZhou
// /clone/board/toplayer_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("天界造物公告板", ({ "board" }) );
        set("location", "/d/wizard/news_room");
        set("board_id", "toplayer_b");
        set("long", "这是一个供天界代理人发布本游戏最新更新的留言板。\n" );
        set("intermud", 1);
        set("poster_level", "(immortal)"); 
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
