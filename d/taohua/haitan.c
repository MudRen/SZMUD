// Code of ShenZhou
// kane, 16/5/97
// modified by aln 4 / 98

#include <ansi.h>

inherit HARBOR;

void create()
{
	set("short", "��̲");
	set("long", @LONG
����������𽭺����һ����ˡ��������ȥ�����˺��콻�ʴ����㺣Ÿ
��Ӱ���������֣����ܼ�����һ����Ӱ�����ɵ�����һ�󷢻š�������һƬ
������ϼ�����֣������ƽ�����ɫ�ͷף��������ĵģ��ƺ�͸�ŹŹ֡�����
ǰ����һ��ʯ��(shibei)�������ƺ���Щ�ּ����Ա���һ���ʯ(stone)��
LONG
	);

	set("exits", ([
		"north" : __DIR__"thzhen1",
	]));

	set("item_desc",([
	    "shibei" : "
����......����......ռ�����......
......����......����......������ʱ......
\n",
	    "stone" : "
��ʯ�Ϸ���һ�鰼�ۣ�����һ��Ť���İ�����״��
\n",
	]));

/*	set("objects", ([
		"/kungfu/class/taohua/xuanfeng" : 1,
		"/kungfu/class/taohua/chaofeng" : 1,
	]));
*/

	set("cost", 2);
	set("outdoors", "taohua");

        set("island", "�һ���");
        set("shape", "��һ�ɼ����˱ǻ���ĺ��紵����");
        set("navigate/locx", 30);
        set("navigate/locy", -180);

	setup();

}

void init()
{
        ::init();

        add_action("do_put", "put");
        add_action("do_pozhen", "pozhen");
        add_action("do_pozhen","����");
}

int do_put(string arg)
{
  object me;
  string item, target;

  me = this_player();

  if (!arg || sscanf(arg, "%s in %s", item, target) != 2)
    return notify_fail("ʲ�᣿\n");

  if (!present("bagua", me))
    return notify_fail("ʲ�᣿\n");

  if (item != "bagua")
    return notify_fail("ʲ�᣿\n");

  if (target != "stone")
    return notify_fail("ʲ�᣿\n");

  message_vision("$N�������Է����ʯ������\n", me);
  message_vision(HIW"ֻ�������������죬�������������߷ֿ���һ��С·������$N��ǰ\n$N��æ���������ԣ��������֡�������$N����ָֻ���ԭ״��\n\n"NOR, me);

  me->move("/d/taohua/xiaojing");

  return 1;

}

int do_pozhen()
{
  object me;

  me = this_player();

  if (me->query_skill("qimen-dunjia", 1) < 120) {
    me->receive_damage("jing", 50);
    me->receive_damage("qi", 50);
    me->receive_damage("jingli", 50);
    message_vision("$Nڤ˼������β�����⣬������ƣ����ͬ����ħһ������Ȼһ������������\n", me);
    me->move("/d/taohua/thzhen1");
    
  } else {

    message_vision(HIW"$N��˼Ƭ�̣����ֵ��������˱仯��ȫ����Ȼ���أ�����һ����Ц������һ�����������֣���һ�䣬��һת����Ӱ�ٲ���\n"NOR, me);

  me->move("/d/taohua/xiaojing");
  }
  return 1;

}
/*
int valid_leave(object me, string dir)
{
	mapping myfam;

  	if (dir) {
        	if (!myfam || myfam["family_name"] != "�һ���") {
         	       me->set_skill("qimen-dunjia", 0);
		}
  	}  
	
	return ::valid_leave(me,dir);
}
*/
