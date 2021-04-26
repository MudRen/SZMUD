//Cracked by Roath
// Room: /d/beijing/fuchengdajie.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 3 */
	  "east" : __DIR__"beihai",
	  "south" : __DIR__"fuchengdajie_s",
	  "north" : __DIR__"fuchengdajie_n",
	]));
    } else {
	set("exits", ([ /* sizeof() == 3 */
	  "west" : __DIR__"fuchengmen",
	  "east" : __DIR__"beihai",
	  "south" : __DIR__"fuchengdajie_s",
	  "north" : __DIR__"fuchengdajie_n",
	]));
    }
}

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���Ƿ������ֵĸ��������֣���ֽ����������ˮ������������Ϣ����Ⱥ
���������������������ֱ���ˣǹ���ա��ٻ�С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ
�ߡ����߿��Կ���������
LONG
	);
	set("no_clean_up", 0);
	fix_exits_for_night(0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}
