// Code of ShenZhou
// road: /zhongnan/foyezhen.c

inherit ROOM;

void create()
{
        set("short","��ү��");

        set("long",@LONG
ֻ���˴���Ϊ��������һ����Ժ����ַ���������ɴ�ػ��ƣ���Ժ��
��ԫ�����ϡ�ɼ����ƺ�����һ����С����Ժ��������һƬƽԭ��
LONG);

		  set("exits",([ "east" : __DIR__"shenheyuan",
							 ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");

		  setup();

}
