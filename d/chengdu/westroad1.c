// Room: westroad3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�㲻֪�����ؾ������˳ɶ������ǣ����������������Եø�����
�塣��ʯ�����ֻ����������ļ����ˣ����������й䡣����������
�֣�������������һ����֣��������и��ô��ҩ�꣬��һЩ������
�˳��õ�ҩ�����ŵ��ӳ�������ҩ��
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "south"      : __DIR__"xidajie2",
	    "northwest"  : __DIR__"yaodian",
	]));
	set("objects", ([
	    "/d/huashan/npc/haoke": 1,
	]));

	setup();
	replace_program(ROOM);
}
