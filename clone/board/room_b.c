//Board//8/01/2001
//by jiuer 

inherit BULLETIN_BOARD;

void create()
{
        set_name("地图地理留言板", ({ "board" }) );
        set("location", "/d/wizard/room_r");
        set("board_id", "room_b");
        set("long", "有关地图地理问题的留言板。\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}