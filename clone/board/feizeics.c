inherit BULLETIN_BOARD;

void create()
{
        set_name("飞贼测试纪录", ({ "board" }) );
        set("location", "/d/city/guangchang");
        set("board_id", "feizeibskill");
        set("long", "这是一个由巫师测试后的报告。\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
