// Code of ShenZhou
//Kane

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����½ׯ�����鷿��������Ŀ��ȫ��ʫ��伮���������ϰ���
���ͭ���������������ǹ�����Ϲ���һ��ˮī���������Ǹ���
������������֮ҹ��ͥ�������ְ����������쳤���������į����
�Ͻ�����һ�ס��ʡ�(poem)�����������ббǶ��һ�������ԣ���
�����ͷ��䲻̫��ġ�
LONG
	);

	set("item_desc", ([
	"poem" : "\n
��ҹ���˲�����������ǧ���Σ���������
���������ƽ��С������ģ�������������

����Ϊ��������ɽ�����ϣ����̡�
�������¸����ݣ�֪���٣��Ҷ���˭����

		������˲���Ϳѻ\n",
	]));

	set("exits", ([
		"west" : __DIR__"dating",
	]));

	set("objects", ([
		"/d/taohua/obj/yijing1" : 1,
		"/d/taohua/obj/yijing2" : 1,
	]));

	set("cost", 1);
	set("outdoors", "taihu");

	setup();
	replace_program(ROOM);
}
