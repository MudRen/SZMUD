//Cracked by Roath
// xiakedao/tulu.c
// modified by aln  5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "��·");
        set("long", @LONG
һ���ȳ����Ļ���С·������������㲻�ò������۾���·
��Ҳ����ƽ̹������ʯ���ڽ��¿Ŀİ��·�ԵĹ�����ʵ���ۣ���
��С�к����������µ�ժ���ӳԡ�
LONG );

      set("exits", ([
		     "east" : __DIR__"caodi",
		     "west" : __DIR__"wanghait",
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);

	setup();
}
