// Code of ShenZhou
// ������
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "������");
    set("long", @LONG
������Ƹ߿����ǿ��ճ��õط��������������ƣ�����б����
�������γ�һ���ʺ磬�㱳��̫�����ǲʺ磬ֻ�����Ƽ������Լ�
����Ӱ����Ӱ�������Ź⻷������ӳ���������ɫ��ϼ�⣬�ǲ�ɫ
��쵵Ĺ��θ�ʷ���Ŀ�������
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"beihai",
	"southwest" : __DIR__"tianhai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
