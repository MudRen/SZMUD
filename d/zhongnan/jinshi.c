// Code of ShenZhou
// road: /zhongnan/jinshi.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
�⾲�ҿյ����ģ�ֻ�м������ӷ���һ�ԣ������Ӵ��������á���
�����Ͻ�˵���ģ����Ե����Ƕ�������ŵ��߶���������������˵ľ�
�ޡ�������������������ͨ��Ů�᷿��
LONG);

		  set("exits",([
		"east" : __DIR__"yinwutin",
		"north" : __DIR__"liangong2",
							 ])
			  );
	  set("cost",1);

		  set("objects",([
					 CLASS_D("quanzhen") + "/cheng" : 1,
		  ]));

		  setup();

}

