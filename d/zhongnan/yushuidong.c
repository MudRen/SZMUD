// Code of ShenZhou
// road: /zhongnan/yushuidong.c

inherit ROOM;

void create()
{
        set("short","���鶴");

        set("long",@LONG
�����鶴Ϊȫ���ǰ���չ�����֮��������ȫ�����Ӿ����ڴ������
ȫ��̵Ĳ���֮�أ����Ǿۻᡣ��ϧ���Ƕ����ѱ���ʯ���⣬��Ȼ������
��ȥ���ƣ��Ƿ���ʲ���书�ؼ���������һ����ɭɭ��С����
LONG);

		  set("exits",([ "east" : __DIR__"haoshanxiaojing2",
							 ])
			  );
	  set("cost",1);

			set("objects", ([
				 __DIR__"npc/wang-zd" : 1,
			 ]));

	 setup();
}

