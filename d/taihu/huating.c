// Code of ShenZhou
//Kane

#include "/d/taihu/guiyun.h"
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���ķ��͵���ͤ��û�����ң���������ľ�������Ϲ���
��ȱ�˰��ڵġ�ʫ�ʡ�(poem)�����ڰ����˼������Ρ�һ��Ѿ����
��Ĩ�����档
LONG
	);

	set("item_desc", ([
	"poem" : "\n
      ������             ������
      ������             ��  ��
      ����             ��  ��
      ���Щ�             ��  ��
      ���ũ�             ��  ��
      ������             ��  ��
      ��ƶ��             ��  ��
      ���婦             ��  ��
      ���ũ�             ��  ��
      ������             ��  ��
      ���ҩ�             ��  ��
      ������             ������

\n",
	]));

	set("exits", ([
		"east" : __DIR__"nanfang",
		"south" : __DIR__"dating",
		"west" : __DIR__"nvfang",
		"north" : __DIR__"huayuan",
	]));
	set("cost", 1);
	set("objects", ([
		"/d/taihu/npc/xiaolan" : 1,
	]));

	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "�һ���") && dir != "south" ) {
	if ( (!myfam || myfam["family_name"] != "�һ���") && dir != "north" )
	   return notify_fail("����ׯ������ͣ��㲻��ס�����\n");
    }

    if ( me->query("gender") == "����" && dir == "west" && present("xiao lan", environment(me)))
	return notify_fail("С�������е�����ɫ�ǣ�������㣬�е�����Ϣ���ڶ��ߣ�\n");

    if ( me->query("gender") == "Ů��" && dir == "east" && present("xiao lan", environment(me)))
	message_vision("С����Ц��Ц��˵������λ"+RANK_D->query_respect(me)+"�Ͽ��ȥ�ɣ�������Ұ��㿴�š�\n", me);

    if ( me->query("gender") == "����" && (dir=="east" || dir=="west") && present("xiao lan", environment(me)))
	return notify_fail("С�������һƲ�죬˵������������ס�����\n");

    return ::valid_leave(me, dir);
}
