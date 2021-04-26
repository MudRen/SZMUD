// Code of ShenZhou
// Ssy

inherit ROOM;
#include <ansi.h>

int valid_leave(object who, string dir);
#include "battlefield.h"

void create()
{
        set("short", HIY"�Խ�ɽׯ"NOR);
        set("long", @LONG
˭Ҳû���뵽��������ɽѩ���о�Ȼ�������ŵ���һ��ׯԺ��
Ժ�⼸��ѩ�ɰ�Ȼ������������ӳ֮�£���������ӳ�䵽��������
�������ϡ��������ĸ����֡��Խ�ɽׯ����Ȼ����������(gate)��
���������ƣ���Ϊ���ء��ű�����һ����ʾ (gaoshi)
LONG
        );
        set("item_desc", ([
                "gate" : "һ�Ⱥ������ƳɵĴ��ţ���Ϊ���ء�\n",
                "gaoshi" : @LONG
����������Ǽ������ĵط�����ȥ���ȺӢ�ã��Խ�ͤ�����Ǳ��䳡�ˣ�
����֮ǰ���Ķ����ᱻ��������˱��ܣ���������ٻ�������ֻ������˵
�����ò�̫�ã�������ʲô��ʧ�Ͳ�Ҫ��Թ�ˣ�

���䳡�ı�����һ����Ժ��Ҳ���������򶷣����䳡���� (out) ����Ϣ�ң�
����ܵ�����Ǵ��Ƕ������û��Լ��Ķ���������Ϣ�ҾͲ����ٽ����䳡�ˣ�
���Գ����������䣬һ��˵����ȥ���

�ڱ��䳡�ʹ�Ժ�ڣ���ҵ��������ܱ����ģ������� kill ����Ҳ��������
�⣮����Ķ��ֻ赹���߱���ɱ������ finish ��������ߵ���Ϣ�ң���
���������Լ���ս����
LONG
		,
        ]));

        set("exits", ([
                "west" : __DIR__"snow3",
        ]));
        set("cost", 1);
        set("outdoors", "tianshan");
        setup();
	set_temp("opened", 0);
}
void init()
{
        add_action("do_open",  "open");
        add_action("do_close",  "close");
        add_action("do_knock",  "knock");
    disableCmds();
}

int do_open(string arg)
{
        object me = this_player();
        if ((!arg) || (arg!="gate"))
	  return 0;
	if ((int)query_temp("opened") != 0)
	  return notify_fail("���Ѿ������ˣ�\n");
        if(!wizardp(me))
	  {
	    message_vision("$Nʹ�����ƿ��ţ����ʲô��Ӧ��û�С�\n", me);
	    return 1;
	  }
	message_vision("$N���һ����ָ�����Ż��ϣ���֨ѽ��һ�����ſ��ˡ�\n", me);
	set("exits/enter",  __DIR__"entrance1");
	set_temp("opened", 1);
	remove_call_out("closegate");
        call_out("closegate", 60);
	return 1;
}

int do_close(string arg)
{
        object me = this_player();
        if ((!arg) || (arg!="gate"))
	  return 0;
	if ((int)query_temp("opened") != 1)
	  return notify_fail("�Ż�û�д��ţ�\n");
        if(!wizardp(me))
	  {
	    message_vision("$Nʹ������ź��ϣ����ʲô��Ӧ��û�С�\n", me);
	    return 1;
	  }
	message_vision("$N���顱��һ������ײ���ˡ�\n", me);
	delete("exits/enter");
	set_temp("opened", 0);

	return 1;
}

int do_knock(string arg)
{
        object me = this_player();
        if ((!arg) || (arg!="gate"))
	  return 0;
	if ((int)query_temp("opened") != 0)
	  return notify_fail("���Ѿ������ˣ�\n");
        if(!wizardp(me))
	  {
	    message_vision("$Nʹ�����˰����ţ�ʲô��Ӧ��û�С�\n", me);
	    return 1;
	  }
	message_vision("$N�������ţ���֨ѽ��һ�����ſ��ˡ�\n", me);
	set("exits/enter",  __DIR__"entrance1");
	set_temp("opened", 1);
	remove_call_out("closegate");
        call_out("closegate", 60);
	return 1;
}

void closegate()
{
	message("info", "�š�֨ѽ��һ���Զ������ˡ�\n", this_object(), 0);
	delete("exits/enter");
	set_temp("opened", 0);

}

int valid_leave(object who, string dir)
{
    if (wizardp(who) || dir!="enter") return ::valid_leave(who, dir);
    if (who->query_all_condition()) {
	return notify_fail("�����ϴ����˶�����ô����˼ȥ���䣿\n");
    }
    return ::valid_leave(who, dir);
}
