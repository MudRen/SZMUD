// Code of ShenZhou
// Room: /d/xingxiu/gcmaze2.c
// Date: June 30, 96   Jay

inherit ROOM;

void create()
{
	set("short", "�߲��Թ�");
	set("long", @LONG
���ں����������㲻����Щ��������֪��ʲ��ʱ��
�����ߵ�ͷ��
LONG
	);

	set("exits", ([
		"out" : __FILE__,
                "enter" : __FILE__,
	]));

	set("cost", 7);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir=="enter") me->add_temp("marks/step",1);
	if (dir=="out") me->add_temp("marks/step",-1);
	if (me->query_temp("marks/step")==5)
	return notify_fail(
"ͻȻ֮�䣬ǰ��һ����ɭɭ����"+
"���ȵ�������������\n�Ѱ���������ס��һǧ�꣬˭Ҳ�����������ҡ���һ��"
+"\n�󵨹��������̾�������\n");

	if (me->query_temp("marks/step")==10) {
	  me->move("/d/xingxiu/gcmaze3");
	  me->delete_temp("marks/step");
//	  return notify_fail("\n"����
return notify_fail("\n");
	}

        if (me->query_temp("marks/step")==-10) {
          me->move("/d/xingxiu/gcmaze1");
          me->delete_temp("marks/step");
//          return notify_fail("������߳�����\n"����
return notify_fail("\n");
        }

	return ::valid_leave(me, dir);
}	
