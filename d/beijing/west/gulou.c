//Cracked by Roath
// Room: /d/beijing/west/gulou.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
���ǹ�¥ÿ��������ʱ�ֱ�Ὺʼ��ģ���������������
ƽ�����������¥��������֪��ʱ���ˡ���¥������ǳ���
�����Ĺ�¥��֣����������ֵĶ�ֱ�Ŵ�֡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"south" : "/d/beijing/east/dianmen",
	"west" : __DIR__"guloudajie2",
	"north" : __DIR__"zhonglou",
	"east" : "/d/beijing/east/dongzhidajie2",
	"southwest" : __DIR__"jingshanjie",
	]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
