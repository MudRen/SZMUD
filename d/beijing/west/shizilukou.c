//Cracked by Roath
// Room: /d/beijing/west/shizilukou.c

inherit ROOM;

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
����һ���������ֵ�ʮ��·�ڣ�·������������������Χ�в���
С�������۸�������ٻ���������Կ�����̳�����ĵ��������
ɽ��̳�������������ţ����������������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"xitianmen",
  	"north" : __DIR__"zhengyangdajie",
	"south" : __DIR__"yonganmen",
	]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
