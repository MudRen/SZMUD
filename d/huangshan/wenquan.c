// Code of ShenZhou
// ��Ȫ
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "����");
    set("long", @LONG
����Ϊ��ɽ���ľ���֮һ����Ȫ(�ֳ�����)���������Ʒ��͵�ʯ
��֮�£�ͬ����ʮ����һ����Ϫ��������ȪȪ��ʯ������š�����
��Ȫ���ĸ����֡���Ȫˮ����̣�������ԡ��
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"renzipu",
	"north" : __DIR__"ciguang",
	"northeast" : __DIR__"baizpu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
// ��Ȫ������������������Ⱥ�ζһϴ���⣬���յ�ƣ������
// ��ʱ��ʧ����е��������࣬����Ϊʫ�䡰���������
// ɽ������Ƿ��ɰһ��Ȫ�����ֽо���
