//Cracked by Roath
// xiakedao/yucun1.c

inherit ROOM;

void create()
{
        set("short", "С���");
        set("long", @LONG
���С�����ֻ��ʮ�����˼ң�ÿ��ÿ������ǰ��ɹ��������ɡ�
�����м��ƽ����ͣ��һ���ƴ���С����������Ǵ��ˡ�
LONG );

      set("exits", ([
		"north" : "/d/quanzhou/gangkou4",
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("objects", ([ 
	    __DIR__ + "npc/helper" : 1,
      ]));
      set("no_clean_up", 1);
	setup();
	replace_program(ROOM);
}




