// Code of ShenZhou
// road: /zhongnan/shishi.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");

        set("long",@LONG
ʯ���з������ʯ��(guan)����������ʯ�׹׸������ܸ��š���˵��
��������ǰ�������塣��������Ĺ׸�ȴֻ����һ�룬Ҳ��֪��������ʬ
�壬�����˵ġ�
LONG);

		  set("item_desc",(["guan" : "
��ʯ�װ뿪�����ţ�Ҳ��֪��û��ʬ�������棬ûʲ��ÿ��ġ�
\n",]));

		  set("exits",([ "east" : __DIR__"zoudao4",
								"down" : __DIR__"midao1",

							 ])
			  );
	  set("cost",1);
	  set("outdoors", "zhongnan");

		  setup();
		  replace_program(ROOM);
}

