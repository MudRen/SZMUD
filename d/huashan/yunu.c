// Code of ShenZhou
// ��ɽ��Ů��
// modified by qfy 26/6/1996

inherit ROOM;

void create()
{
        set("short", "��Ů��");
	set("long", @LONG
�����ǻ�ɽ���з壬��Ů�塣��Ů�������Ϊƽ�������������ķ��
�վ��������Ϻպ������Ļ�ɽ���ɾ��ڴ˴�����������СС������Ǿ�
����Ů���ˡ�����ϡϡ������ʮ���䷿�ӣ��ǻ�ɽ�ɵĵط��������ο���
�ñ�������ȥ��
LONG
        );
        
	set("exits", ([ /* sizeof() == 4 */
  	 	"northdown" : __DIR__"zhenyue",
  		"east" : __DIR__"yunuci",
  		"south" : __DIR__"square",
  		"northup" : __DIR__"shanlu1",
		"westdown" : __DIR__"xiaolu1", 
	]));
	
	set("objects", ([
		__DIR__"npc/s-houzi" : 2,
		__DIR__"npc/b-houzi" : 1,
		"/clone/obj/car" : 1,
	]));

        set("outdoors", "huashan" );
        set("fjing", 1);

	set("cost", 3);
        setup();
        replace_program(ROOM);
}
