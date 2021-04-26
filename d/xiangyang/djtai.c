// Code of ShenZhou
// Room: /d/xiangyang/djtai.c

inherit ROOM;

void create()
{
	set("short", "�㽫̨");
	set("long", @LONG
��̨�������ţ������˵㽫̨����������̨֮�������׻�̨֮����̨ɭ�ʣ�
�ɸ����ɡ��㽫̨�ײ�Ϊ��ʯ���ɣ�������һƽ̨��һ��սʱ����˧������̨��
�ݸ߶�������������
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
        set("coordinates", ([ "x" : -3, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"nanjie2",
  "north" : __DIR__"ceting",
  "northwest" : __DIR__"xiaoshi",
  "west" : __DIR__"ximen",
]));

	setup();
	replace_program(ROOM);
}
