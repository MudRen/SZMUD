//Cracked by Roath
// Room: /d/beijing/west/tianqiao3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ѿ����������ĵش�����Χ�˳���ͬ��ˮһ�������˷�ӿ
�����㱻��Ⱥһ����������������ǰ��ȥ����������ˣ���գ�������
�У��㲻�ɵð���̾�����ӽ��¹�Ȼ����Ƿ���������һ�Ҵ��ݣ�
�����������¥��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"chaguan",
	"west" : __DIR__"mingyuelou",
	"north" : __DIR__"tianqiao1",
	"east" : __DIR__"tianqiao4",
	]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
