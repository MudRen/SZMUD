//Cracked by Roath
// Room: /d/beijing/chongwenjie.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 3 */
	  "north"  : __DIR__"chongwenmen",
	  "west"  : __DIR__"zhengyangdajie",
//	  "northeast": __DIR__"tianshuijing",
	]));
    }else{
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"zuoanmen",
	  "north"  : __DIR__"chongwenmen",
//	  "northeast": __DIR__"tianshuijing",
	  "west"  : __DIR__"zhengyangdajie",
	  "east"  : __DIR__"guangqumen",
	]));
    }
}

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���������ֵĳ����Ŵ�֡����϶������������ˣ���ʱҲ�ܿ��������Ŵ��
ҪԱ������
LONG
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}
