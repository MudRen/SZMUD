// Code of ShenZhou
// road: /zhongnan/heifongdong.c

inherit ROOM;

void create()
{
        set("short","�ڷﶴ");

        set("long",@LONG
�˴�λ�����ɽ��������̫��ɽ�ϡ�ֻ��ɽ��ֱ��ֱ�£����а��
���ͣ�ֻɽ������һ�������Ӵֵ�ʯ������ʱð��һ�ɺ������ֿ��µġ�
������һƬ���֡�
LONG);

		  set("exits",([ "westup" : __DIR__"shulin3",
							 ])
			  );
	  set("cost",3);
	  set("outdoors", "zhongnan");

		  setup();

        replace_program(ROOM);
}
