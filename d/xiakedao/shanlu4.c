//Cracked by Roath
// xiakedao/shanlu4.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ͨ��ɽ����С·��·���Ӳݴ�����������һЩ��֪����Ұ����
���ܾ����ĵ�û����������������������һ��ɽҰ�ķҷ�ֱ�����顣
LONG );

      set("exits", ([
		"westup" : __DIR__"shanding",
		"northdown"  : __DIR__"shanxia",
      ]));
      set("no_clean_up", 1);
	set("objects", ([ 
          "/d/city/obj/branch4" : 1,
      ]));
	
	set("outdoors", "xiakedao" );
	set("cost", 2);
	setup();
}

