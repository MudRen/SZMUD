//Cracked by Roath
// xiakedao/xiaolu2.c
// ssy

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "С·");
        set("long", @LONG
������ʯ�̳ɵ�С·�ϣ��Ų�ʮ����ݡ�������Լ�ɼ��󺣣���
������һ��ɽ·��С·���Զ������֣�֦Ҷ������գ�������ȸߴ����
������ķ������һƬ��
LONG );

      set("exits", ([
		     "south" : __DIR__"ybting",
		     "north" : __DIR__"wanghait",
		     "eastup"  : __DIR__"shanlu3",
		     "west":__DIR__"haibian2",
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("objects", ([ 
	    __DIR__ + "npc/dahan" : 1,
          "/d/city/obj/branch1" : 1,
          "/d/city/obj/branch2" : 1,
      ]));

	setup();
}
