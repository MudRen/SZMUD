//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "����ի");
	set("long", @LONG
����֮����ի�������Ϊ����ի��Ϊһ����֮԰��԰������̫������ʱ֮
����������Ϊ�ɳأ��ر�Ϊ�ã��ú���ɽ�أ����ҽԷ����Ҷ��������з�����
ˮ�����ӻء������г������䣬����Ȫ�ȣ��Ⱥ���ɽʯ�ر���ΪǬ¡ʱ��ʯ֮
��Ʒ���鲼̫֮��ʯɽ����������͸���������ڴ���ľ�е�̨ͤ���Ż����
ӳ����ɫ���š�
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "east" : __DIR__"houmen",
                "southwest" : __DIR__"xitian",
                ]));
	
	
	setup();
	replace_program(ROOM);
}
