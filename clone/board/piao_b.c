// room:/u/piao/piao_b.c
//piao 2001.9.10

inherit BULLETIN_BOARD;

void create()
{
        set_name("留言簿",({"board"}));
        set("location","/u/piao/workroom");
        set("board_id","piao_b");
        set("long",@LONG
有话对飘说，就请在这里留言吧。
LONG);
        setup();
        set("capacity",300);
        replace_program(BULLETIN_BOARD);
}

