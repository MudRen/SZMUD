// Code of ShenZhou
// Room: /d/xiangyang/milin.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����У�פ���ع����о�����۲��ѡ���Ȼɽ���߶����ţ�ˮ�����
���壻�ز����ƽ̹���������ïʢ�����򽻴䣬Գ�����ס��Դ�ɽ֮�ϣ�һ
���߸ڣ��������ڡ���ǰ������é«�У���Ϧ�����������֮�ء��ڴ�ң����
���ڣ���Ȼ�徰�쳣��
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -16, "y" : -3 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guangde",
]));

	setup();
	replace_program(ROOM);
}
