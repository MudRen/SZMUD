
// ����ܰ(Athena) 
// Room��/u/athena/shizilin.c 

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ʨ����");
	set("long", @LONG
��һ�߽�ʨ���֣��㲻��Ϊ��������԰�ֵ������������۷�
��ʨ���ֶ��϶�ɽ��������ˮ�����С���ɽ������֮�ơ���ɽ��
�͵��֣�����������ʯ�����಻�ϣ�����Ī�⡣���֮�䣬����
�����ɼ���������������Թ������ɵò�Ϊ֮��̾���ѡ�
LONG
	);
	set("exits", ([
	"west" : __DIR__"liuyuan",
        ]));
 	set("outdoors", "Sufu");
        setup();
}

