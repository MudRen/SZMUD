// Code of ShenZhou
// husun.c

inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
ǰ������һ��ʮ�ֶ��͵�ɽ�룬��������ֻ��Գ���̾�̨�ϣ���˵��
ǰ�ӻ�ɽˮ����������Գ�ÿ�������Ҫ����ȥ��������Ҳ�е����ڳ�
Խ���������������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"northdown" : __DIR__"laojun",
  		"southup" : __DIR__"canglong",
	]));
	
	set("objects", ([
	         __DIR__"npc/s-houzi" : 2,
	         __DIR__"npc/b-houzi" : 2,
	]));         
	
        set("no_clean_up", 0);
        set("fjing", 1);
        set("outdoors", "huashan" );

	set("cost", 6);
        setup();
        replace_program(ROOM);
}
 
