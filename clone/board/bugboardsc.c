inherit BULLETIN_BOARD;

void create()
{
        set_name("你发现事情不大对了，可是又说不上来 - 留言板", ({ "board" }) );
        set("location", "/d/city/guangchang");
        set("board_id", "errorboard");
        set("long", "如过你看到 你发现事情不大对了，可是又说不上来。 请把问题 post 到这里。\n需要大致上说以下的东西\n-哪里发生的\n-什么情况发生\n\n当然, 资料越多我们就修的越快\n\n最后谢谢您的配合。" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
