// room:/u/piao/piao_b.c
//piao 2001.9.10

inherit BULLETIN_BOARD;

void create()
{
        set_name("���Բ�",({"board"}));
        set("location","/u/piao/workroom");
        set("board_id","piao_b");
        set("long",@LONG
�л���Ʈ˵���������������԰ɡ�
LONG);
        setup();
        set("capacity",300);
        replace_program(BULLETIN_BOARD);
}

