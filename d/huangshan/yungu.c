// Code of ShenZhou
// �ƹ�
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "�ƹ�");
    set("long", @LONG
���ǲ��Ϸ���޺���֮���һ��Ͽ�ȡ�վ�ڹȵ����룬�������ܣ�
�������档Զ�������ƻ����Ƶ�ΡΡȺ�壬�������Ա��齦��ı�
Ϫ��Ȫ��������һ��ɲ���ഫ�ϱ���ʱ����һɮ�����ε������
Ҳ�����뿪��������������𣬸���������ȡ�������֡����и���
��������������ϲ֮��ӱ����ˡ��ƹȡ����֣�������ͷ����Ϊ��
��ʵ������ƹ��¡�����ǰ������ǧ�����������һ������ɼ��
����һ���ǻ�ɼ��
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"southwest" : __DIR__"shanlu1",
	"southeast" : __DIR__"jiulong",
	"northup" : __DIR__"xianren",
	
		 ])
	 );
    setup();
    replace_program(ROOM);
}
