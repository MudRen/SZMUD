// Code of ShenZhou
// ʯ��
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "ʯ��");
    set("long", @LONG
ɽ��Խ��Խ�����Խ��Խ����ɽ�߱��գ�����̦�����������
�������٣�ȡ����֮���Ǹ�����������ľ��ÿ�����϶��������ܵ�̦
޺���ұ��ϡ�ʯ����Ҳ����̦޺����;ʯ���г������곣�̵�������
�������ϴ�������������ɫ���ٲ���
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"shijie3",
	"down" : __DIR__"shijie5",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
