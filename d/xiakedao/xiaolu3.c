//Cracked by Roath
// xiakedao/xiaolu.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "С·");
        set("long", @LONG
����һ����ͨ��ʯ��·��·����ʯ���������ţ��Գ�������ͼ
����
LONG );

      set("exits", ([
		     "south" : __DIR__"shanxia",
		     "east" : __DIR__"jiaoshi1",
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 0);
	set("objects", ([ 
          "/d/city/obj/branch3" : 1,
      ]));
	setup();
}
