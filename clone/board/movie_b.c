/* /kungfu/class/movie/center.c
** ���ݵ�ӰԺ���԰�
** created by yujie
** created in 11/2001
*/

inherit BULLETIN_BOARD;

#include <ansi.h>

void create()
{
        set_name("���ݵ�ӰԺ���԰�", ({ "board" }) );
        set("location", "/kungfu/class/movie/center");
        set("board_id", "movie_b");
        set("long", "���ǵ�ӰԺר�õ����԰塣\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}

