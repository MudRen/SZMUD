// Code of ShenZhou
// road: /zhongnan/river.c

inherit ROOM;

void create()
{
		  set("short", "С�ӱ�");

		  set("long",@LONG
�˴�λ�����ɽ��һƫƧ����ֻ��Ũ���ѵأ����⸡������Χ������
���ľ���ľ��ľ�֮������Զ����С����ɽ��(dong)��ӿ����Ȫˮ���γɣ�
���ȵ�ˮ���������������˳����������ͨ��ɽ����������ɽ���ɽ��
�С�
LONG);

		  set("exits",([ "enter" : __DIR__"dong",
								"north" : __DIR__"xiaojing1",
							 ]));

	  set("item_desc",(["dong" : "
	С��������ĵģ�һ��Ȫˮ��������������֪ͨ���δ���
\n",]));

	  set("cost",2);
	  set("outdoors", "zhongnan");

		  setup();
	  set("outdoors","zhongnan");

		  replace_program(ROOM);
}

