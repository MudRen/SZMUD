//Cracked by Roath
// Room: /d/beijing/xizhidajie.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"fuchengdajie",
	  "east" : __DIR__"guloudajie_w",
	]));
    } else {
	set("exits", ([ /* sizeof() == 3 */
	  "northwest" : __DIR__"deshengmen",
	  "west" : __DIR__"xizhimen",
	  "south" : __DIR__"fuchengdajie",
	  "east" : __DIR__"guloudajie_w",
	]));
    }
}

void create()
{
	set("short", "��ֱ�Ŵ��");
	set("long", @LONG
����һ��ʮ�ֿ����Ĵ�֡������������൱���֡��м���С��
�����ؽֽ�����ʲ�ᣬż�м������˻�ͣ����פ���ʼۡ������Ǹ�
���Ŵ�֣�����������ֱ�š�
LONG
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}
