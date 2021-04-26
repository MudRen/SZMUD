// Code of ShenZhou
// Room: /city/minwu1.c
// YZC 1996/11/13 

#include <ansi.h>
inherit ROOM;

int do_move(string arg);
int do_look(string arg);

#define SKILL_DB "/clone/obj/skill_db"

void create()
{
	set("short", "����");
	set("long",
"����һ�����͵���ͨ�ϰ���ס�ݡ��ͱ������һ�������������ƾɵ�������
ֻ�ڷ���һ�ž����Ӻͼ����ϴ��������������ڴ���˯�����������ף������Щ
׳�������۵��ˡ��㷢���ұ�С��������һ������û���µ�Ӥ����Ц���еؿ�
���㣬���Ҳ���ޡ�����һ��С͵�Ƶ��ڷ�����������ȥ��������ǽ�ŷ���һ��
��"+YEL"�׸�"NOR+"(gang)��\n"
	);

	set("exits", ([
		"south" : __DIR__"xiangnanjie",
	]));

	set("objects", ([
		__DIR__"npc/man" : 2,
	]));

	set("cost", 0);
	setup();
}

int init()
{
    add_action("do_move", "move");
    add_action("do_look", "look");
}

void print_enter(mapping enter)
{
	string *names;
	int i, n;

 	n=0;
	if (mapp(enter)) {
   	    names = keys(enter);
	    for (i=0; i<sizeof(names); i++) {
		printf("    %s ������ %d �Σ�\n", names[i], enter[names[i]]);
		n++;
	    }
	}
	if (n == 0) {
	    printf("û�˽�������\n");
	}
}

int do_look(string arg)
{
    object player = this_player();
    object db;
    mapping enter;

    if (arg != "gang") {
        return notify_fail("��Ҫ��ʲô��");
    }
    if (!wizardp(player) && !player->query("futou_bang")) {
        message_vision("$N�����׸׿��˰��죬�����׸����в����׳森\n",
	    player);
    }else{
        message_vision("$N��ϸ�쿴�׸ף��ƺ����о������ָ�ƣ�����\n",
	    player);
	db = find_object(SKILL_DB);
        if (!objectp(db)) db = new(SKILL_DB);
        if (!objectp(db)) {
	    message_vision("$N, �������ʦ��skill_db ���ܱ� clone��", player);
	    return 1;
 	}
   	enter = db->query("futou/enter");
        printf("�㷢�֣�\n");
	print_enter(enter);
	if (!wizardp(player)) {
	  message_vision("$N��ϸ�ز��˲��׸׵ı�Ե��\n", player);
	  db->delete("futou/enter");
	}
	db->save();

	if (wizardp(player)) {
	    printf("�ӹŵ��񣬽������ҵ��У�\n");
	    print_enter(db->query("futou/enter_all"));
	}
    }
    return 1;
}

mapping add_enter(mapping enter, object player)
{
  string id = player->query("id");
  int n;

  if (mapp(enter)) {
    n = enter[id];
    enter[id] = n+1;
    return enter;
  }else{
    return ([id:1]);
  }
}

int do_move(string arg)
{
    object player = this_player();
    object db;
    mapping enter;

    if (arg != "gang") {
        return notify_fail("��ҪŲʲô��");
    }
    if (player->query("ftb_job_num") > 1000) {
      message_vision("$N��Ҫȥ���׸ף�ͻȻ׳����$NһЦ����$Nһ���ţ���$N������Աߵ�С�ţ�\n",
		     player);
    player->move("/d/city/ftb_mishi");
    player->delete("ftb_job_num");
    player->set("mishi",1);
    
   return 1;
}


    if (player->query("combat_exp") < 10000 ||  player->query("max_neili") < 1000) {
      message_vision("$Nʹ���˾�ȥ���׸ף������׸��ƺ����ڵ���һ�㣬��˿������\n",
		     player);
    }else{
      message_vision("$NŲ���׸ף����Ϻ�Ȼ��¶��һ�����ڣ�$N�Ӷ������˽�ȥ��\n",
		     player);
      player->move("/d/city/ft_room1");

      if (!player->query("futou_bang")) {
	message_vision("$N��ս�ľ�����С���ߵ��˵��ϵ�һ��ľ׮��\n", 
		       player);
      }
      db = find_object(SKILL_DB);
      if (!objectp(db)) db = new(SKILL_DB);
      if (!objectp(db)) {
	message_vision("$N, �������ʦ��skill_db ���ܱ� clone��", player);
      }else{
	enter = db->query("futou/enter");
	enter = add_enter(enter, player);
	db->set("futou/enter", enter);

	enter = db->query("futou/enter_all");
	enter = add_enter(enter, player);
	db->set("futou/enter_all", enter);

	db->save();
      }
      message_vision("$N�Ӷ������˽�����\n", player);
    }
    return 1;
}
