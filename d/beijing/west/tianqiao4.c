//Cracked by Roath
// Room: /d/beijing/west/tianqiao4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ѿ����������ĵش�����Χ�˳���ͬ��ˮһ�������˷�ӿ
�����㱻��Ⱥһ����������������ǰ��ȥ����������ˣ���գ�������
�У��㲻�ɵð���̾�����ӽ��¹�Ȼ����Ƿ���������һ���鱦�꣬
������һ�ұ����̡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"zhubaodian",
	"north" : __DIR__"tianqiao2",
	"west" : __DIR__"tianqiao3",
	"east" : __DIR__"bingqipu",
	]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
