//Cracked by Roath
// Room: /d/beijing/west/tianqiao2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ѿ����������ĵش�����Χ�˳���ͬ��ˮһ�������˷�ӿ
�����㱻��Ⱥһ����������������ǰ��ȥ����������ˣ���գ�������
�У��㲻�ɵð���̾�����ӽ��¹�Ȼ����Ƿ���������һ���鱦�꣬
������һ�������С�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"paimaihang",
	"south" : __DIR__"zhubaodian",
	"west" : __DIR__"tianqiao1",
	"east" : __DIR__"zhengyangdajie",
	]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
