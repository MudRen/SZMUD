//Cracked by Roath
// xiakedao/shanlu1.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������ʯ�̳ɵ�С·�ϣ��Ų�ʮ����ݡ����Զ������֣�֦Ҷ��
����գ��������ĺܲ������������ȸߴ����������ķ������һƬ��
LONG );

      set("exits", ([
      	"south" : __DIR__"ybting",
		"north" : __DIR__"shanlu2",
		"eastup"  : __DIR__"shanlu3",
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
