//  ���ǳ�Ϯ���������վ������������趨�˰���ID����  //  /clone/board/duchang_b.c
//  by naihe  2002-04-09

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name("�ĳ����԰�", ({ "board" }) );
        set("location", "/clone/misc/naihe/dc_dating");
        set("board_id", "duchang_b");                                
        set("long","���Ƕĳ������԰棬����ǿ��������ｻ���ĵá���ҫս����ѯ������ȡ�\n"
);
        setup();
        set("capacity", 500);
        replace_program(BULLETIN_BOARD);
}
