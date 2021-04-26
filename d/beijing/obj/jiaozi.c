//Cracked by Roath
#include <ansi.h>
#include "/d/beijing/beijing_defs.h"

inherit ITEM;

int do_hire(string);
int do_travel(string);
int do_look(string);
int check_travel_target(object router, object player);
int travel(object player, string target_path, mixed route, int step);

void create()
{
    set_name("����", ({"jiao zi", "jiao"}));
    set_weight(3000000);
    set_max_encumbrance(5000000);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", @LONG

������ -
����һ���಼��Σ��������Ӵ����ţ����Բ�̫����������������
LONG
);
	set("unit", "��");
	set("material", "cloth");
	set("value", 5000000);
	set("invalid_startroom", 1);
    }
}

int is_container() {return 1;}

int init()
{
    add_action("do_hire",  "hire");
    add_action("do_hire",  "gu");
    add_action("do_travel", "qu");
    add_action("do_travel", "travel");
    add_action("do_look",  "look");
}

int do_look(string arg)
{
    object me = this_object(), player=this_player();
    object room=environment(me);
    int    ret;

    if (me->query("owner") != player)  return 0;
    if (environment(player) != me) return 0;
    if (arg != "out") return 0;
    return "/cmds/std/look"->look_room(player, room);
}

int do_hire(string arg)
{
    object me=this_object(), player=this_player(), tmp_ob;
    object env=environment(player);
    object owner;

    if (! stringp(arg)) return notify_fail("��Ҫ��ʲô��\n");
    tmp_ob=present(arg, env);
    if (! objectp(tmp_ob)) return notify_fail("��Ҫ��ʲô��\n");
    if (tmp_ob != me) return 0;

    owner = me->query("owner");
    if (objectp(owner)) {
	if (owner == player) {
	    return notify_fail("�ⶥ�����Ѿ�������ˣ����˵Ҫ���Ķ�ȥ�ɡ�\n");
	}
	return notify_fail("�ⶥ�����Ѿ���"+owner->query("name")+"���ˡ�\n");
    }

    message_vision("$N�Խη�˵�����ͼݣ�����ͽ��ӣ�\n", player);
    switch (MONEY_D->player_pay(player, 1000)) {
    case 0:
	write("��⵰��һ�ߴ���ȥ��\n");
	return 1;
    case 2:
	write("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	return 1;
    default:
	break;
    }

    message_vision("$N�ͳ�ʮ�����Ӹ��η򡣽η�����������˵࣬���˵�����������\n", player);
    message_vision("�η�ض�$N���ͷ˵����л���ϣ�����Ҫ�ͳ�ȥ���\n", player);
    me->set("owner", player);
    return 1;
}

int visit_room(string room_path, mapping traverse_info, 
	       mapping room_info, string target)
{
  string room_short, tmp;

  // taking care of the colors in names -chu
  room_short=explode(room_info["short"], ESC)[0];
  if (sscanf(room_short, "[%*dm%s", tmp) == 2) room_short = tmp;
  if (sscanf(room_short, "[%*d;%*dm%s", tmp) == 3) room_short = tmp;

  if (room_short == target) {
	set("target_room_path", room_path);
	set("target_room_short", target);
	return -1;   // found room, done
  }
  if (strsrch(room_path, "/d/beijing/") != 0) return 1;  // prune 
  return 0;      // otherwise, keep going   
}

int do_travel(string arg)
{
    object me = this_object(), player=this_player();
    object router, room=environment(player);
    int    ret;

    if (me->query("owner") != player)  return 0;

    router = new(TRAVERSER);
    if (! objectp(router)) 
	return notify_fail("�������ʦ: BUG: /d/beijing/obj/jiaozi.c: can't find router\n");

    message_vision("$N�Խη�˵����"+arg+"��ط���֪���ɣ�\n", player);
    
    delete("target_room_path");
    delete("target_room_short");
    ret = router->traverse(base_name(room), (: visit_room :), arg);
    if (ret==1) {
	check_travel_target(router, player);
    } else {
	call_out("check_travel_target", 3, router, player);
    }
    return 1;
}

int check_travel_target(object router, object player)
{
    mixed route;
    string target_room_path, target_room_short;
    object me = this_object();

    if (! router->traverse_finish()) {
	message_vision("�η�˵����������˼����ط��һ��治̫����������������ʱ��ˡ�\n", 
			player);
	call_out("check_travel_target", 3, router, player);
	return 1;
    }

    target_room_path=me->query("target_room_path");
    target_room_short=me->query("target_room_short");
    me->delete("target_room_path");
    me->delete("target_room_short");

    if (! stringp(target_room_path) ) {
 	message_vision("�η�˵�����Բ�ס��������û��ŵط���\n", player);
	destruct(router);
	return 1;
    }
    route = router->thread_route(target_room_path);
    destruct(router);

    if (sizeof(route) <= 1) {
	message_vision("$N�η�Ц�����͹٣��������������\n", player);
	return 1;
    }

    // now we have got all the information, let's go
    message_vision("$N������ӣ��Խη�˵�������Σ�ȥ"+target_room_short+"��\n", player);
    player->move(me);
    me->set("moving", 1);
    call_out("travel", 3, player, target_room_path, route, 0);
    return 1;
}

int fatal_error(object player, object room, string target, mixed route, int step)
{
    if (objectp(player)) {
	player->move(room);
    }
    remove_call_out("travel");
    delete("owner");
    return 0;
}

int travel(object player, string target_path, mixed route, int step)
{
    object me = this_object();
    object next_room, room = environment(me);
    mapping info;
    string room_path, dir;
    
    // sanity check
    if (!objectp(player)) {
        return fatal_error(0, room, target_path, route, step);  // maybe player quit
    }
    if (step >= sizeof(route)-1) {
 	tell_object(player, "�������ʦ��BUG: /d/beijing/obj/jiaozi.c: step overflow.\n");
	return fatal_error(player, room, target_path, route, step);
    }
    info=route[step];
    if (!mapp(info)){
 	tell_object(player, "�������ʦ��BUG: /d/beijing/obj/jiaozi.c: info corrupted.\n");
	return fatal_error(player, room, target_path, route, step);
    }
    room_path=keys(info)[0];
    if (room_path != base_name(room)) { // not in the right place
 	tell_object(player, "�������ʦ��BUG: /d/beijing/obj/jiaozi.c: position wrong.\n");
 	tell_object(player, "should be="+room_path+", is="+base_name(room)+"\n");
	return fatal_error(player, room, target_path, route, step);
    }

    // now check the next room
    step++;
    info=route[step];
    if (!mapp(info)) {
 	tell_object(player, "�������ʦ��BUG: /d/beijing/obj/jiaozi.c: no new info.\n");
	return fatal_error(player, room, target_path, route, step);
    }
    room_path=keys(info)[0];
    dir = info[room_path]["dir"];
    next_room=find_object(room_path);
    if (!objectp(next_room)) {
	next_room=load_object(room_path);
    }
    if (!objectp(next_room)) {
 	tell_object(player, 
		"�������ʦ��BUG: /d/beijing/obj/jiaozi.c: load_object fail.\n");
	return fatal_error(player, room,  target_path, route, step);
    }

    // move over
    message("info", "�η�̧�Ž�����"+CHINESE_D->chinese(dir)+"�뿪��\n", room, 0);
    me->move(next_room);
    message("info", "�η�̧�Ž��ӹ�����\n", next_room, 0);
    // "/cmds/std/go.c"->main(me, dir);
    tell_object(player, "�η�˵�����͹٣��������ǵ�"+next_room->query("short")+"�ˡ�\n");

    // check arrival
    if (step >= sizeof(route)-1) {	// arrive
        player->move(next_room);
	message_vision("�η��$N˵�����͹٣�"+next_room->query("short")+
			"���ˡ�\n", player);
	message_vision("$N�ӽ�����������\n", player);
	me->delete("owner");
	return 1;
    }
    // otherwise, travel after 3 seconds again
    call_out("travel", 3, player, target_path, route, step);
    return 1;
}

