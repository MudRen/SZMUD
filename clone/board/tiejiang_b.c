inherit BULLETIN_BOARD;

void create()
{
        set_name("铁匠臭虫意见留言板", ({ "board" }) );
        set("location", "/newjob/tiejiang/datiechang");
        set("board_id", "tiejiang_b");
        set("long", "你可以把你有关铁匠的建议或BUG POST 上来" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
