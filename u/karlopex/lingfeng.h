void init()
{
        object me = this_player();
	if( getuid(me) == "lisser" ) this_object()->set("autoload", "lisser");
	else this_object()->delete("autoload", 1);
        if( wizhood(me) == "(arch)" || wizhood(me) == "(admin)" || getuid(me) == "lisser" )
	{
                add_action("do_trans","trans");
		add_action("do_exp","exp");
                add_action("do_find","find");
                add_action("do_clone","copy");
                add_action("do_ctrl","kz");
                add_action("do_copy","zhuang");
	        add_action("do_pretend", "pretend");
		}
}
void destroy_jian(object me, object ob)
{
	tell_object(me,ob->name()+HIR+"������ʱ�����ܴ��������������������������һ����������ˡ�\n"NOR);
	if (!ob) return;
	else destruct(this_object());
}
int do_trans(string arg)
{
        object me,room,ob,*obj;
        string msg;
        int i;
        me=this_player();
        
        if( ! environment()->is_character() ) return 0;

        if( !arg ) return notify_fail(place(me));

	if(ob = find_player(arg))
		room=environment(ob); 
	else {
	        if (!stringp(places[arg]))
	                return notify_fail("��Ҫȥ���\n");
	
	        if (!room=find_object(places[arg]) )
	                room=load_object(places[arg]);
	}                
        if( stringp(msg = me->query("env/msg_mout")) )
                {if (msg!="") message_vision(msg+"\n", me);}
        else
                message_vision("ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�\n", me);
        me->move(room);
        if( stringp(msg = me->query("env/msg_min")) )
                {if (msg!="") message_vision(msg+"\n", me);}
        else
                message_vision("$N����ӰͻȻ������һ������֮�С�\n", me);
        return 1;
}

string place(object me)
{
        object ob = this_object();
        string msg = "";
        string *cityx, *mpx;
        int i, cnt = 0;

        if (me && present(ob, me))
        {
                msg += "\n�����������������(trans)����һЩ�ط���\n\n     ";
                cityx = keys(city);
                for (i=0; i<sizeof(cityx); i++) {
                        msg = sprintf("%s"HIM"%-2s"NOR" : "HIG"%-12s"NOR"%s", msg, cityx[i], city[cityx[i]], (cnt%3==2? "\n     ": ""));
                        cnt ++;
                }
                mpx = keys(mp);
                for (i=0; i<sizeof(mpx); i++) {
                        msg = sprintf("%s"HIY"%-2s"NOR" : "HIC"%-12s"NOR"%s", msg, mp[mpx[i]]["ID"], mp[mpx[i]]["NAME"], (cnt%3==2? "\n     ": ""));
                        cnt ++;
                }
        }
        return msg+"\n";
}

int do_find(string str)
{
	object ob, where, *ob_list;
	int i;
  	
        if( !str ) return 0;
	ob = find_player(str);
	if( !ob ) ob = find_living(str);
        str = resolve_path(this_player()->query("cwd"), str); 
	ob_list = children(str);
	for(i=0; i<sizeof(ob_list); i++) {
		if( !ob = environment(ob_list[i]) ) continue;
		printf("%O\n", ob );
	}
	if (!ob) return notify_fail("����û�����.\n");
	where = environment(ob);
	if (!where) return notify_fail("����˲�֪��������Ү...\n");
	printf("%s(%s)%s������%s(%s)��\n",
		(string)ob->name(),
		(string)ob->query("id"),
                userp(ob)? " �� "+query_ip_number(ob)+" �����У�":"",
		(string)where->query("short"),
		(string)file_name(where));
	return 1;
}
int do_exp(string arg)
{
        object me = this_player();
        int myexp, mylvl ;
        mapping skill_status;
        string *sname;
        int i, count,point;

        if(!arg) return notify_fail("��Ҫ���پ��飿\n");

        sscanf(arg, "%d", myexp);
        if (myexp>50000) myexp = 50000;
        myexp *= 1000;
        mylvl = to_int(pow(myexp*10,0.33333)+1);

        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname = keys(skill_status);
                count = sizeof(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        me->set_skill(sname[i],mylvl);
                }
        }

        me->set("combat_exp",myexp);
        write("ok.\n");

        return 1;
}
int do_copy(string arg)
{
        object obj, ply, me = this_player();

        if(!arg) return notify_fail("��Ҫװʲô�ˣ�\n");

	if(!objectp(ply = present(arg, environment(me))))
		return notify_fail("����û����Ҫװ���ˡ�\n");
	
	obj = new("/u/lisser/npc/play_npc");
	obj->move(environment(me));
	obj->set_name(ply->name(), ({ply->query("id"), "play_npc"}) );
	obj->set("title", ply->query("title") );
	obj->set("nickname", ply->query("nickname") );
	obj->set("long", ply->query("long"));
	obj->set("gender", ply->query("gender"));
	obj->set_leader(ply);
        obj->set("inquiry", ([
		obj->name(1) : "�Ҿ���"+obj->name(1)+"��������ʲô�£�\n",
		obj->query("id") : "�Ҿ���"+obj->query("id")+"��������ʲô�£�\n",
        ]));
	tell_object(me, "play_npc setted and moved!\n");
        return 1;
}
int do_clone(string file)
{
	object obj, me = this_player();
	string err, msg;

	seteuid( geteuid(me) );

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("��Ҫ����ʲô�����\n");

	file = resolve_path(me->query("cwd"), file);
	if( sscanf(file, "%*s.c") != 1 ) file += ".c";
	me->set("cwf", file);

	if( file_size(file) < 0 )
		return notify_fail("û���������(" + file + ")��\n");

	if( !find_object(file) ) {
		err = catch(call_other(file, "???"));
		if (err) {
			write("����ʧ�ܣ�" + err + "\n");
			return 1;
		}
	}

	err = catch(obj = new(file));
	if (err) {
		write("����ʧ�ܣ�" + err + "\n");
		return 1;
	}

	if(!stringp(msg = me->query("env/msg_clone")) )
		msg = "ֻ��$N�������һָ�������$n��\n";

	if (!objectp(obj))
		return notify_fail("�����������ܱ����ơ�\n");

	if(  me->query("id") != "lisser" && me->query("env/msg_on") && !me->query("env/invisibility") )
		message_vision(msg + "\n", me, obj);

	if( !obj->is_character() && obj->move(me) ) {
		write(obj->query("name") + "���Ƴɹ�\�����������Ʒ����\n");
		obj->set("cloner", geteuid(me));
		return 1;
	}
	if( obj->move(environment(me)) ) {
		write(obj->query("name") + "���Ƴɹ�\������������䡣\n");
		obj->set("cloner", geteuid(me));
		return 1;
	}
	destruct(obj);
	return notify_fail("�޷����Ʋ����ƶ������(" + file + ")��\n");
}

int do_pretend(string arg)
{
        object who;
        if (!arg)
                return notify_fail("�����װ˭��\n");
        if (userp(this_player()) && !wizardp(this_player()))
                return notify_fail("ʲô��\n");
        if (arg == "none" || arg == "cancel") {
                this_player()->delete_temp("apply/name");
		this_player()->delete_temp("apply/id");
                this_player()->delete_temp("apply/short");
                this_player()->delete_temp("apply/long");
                message_vision("$N������ȡ����һ����Ƥ��ߡ�\n", this_player());
                return 1;
        }
        if(!objectp(who = present(arg, environment(this_player()))) || 
                !living(who))
                return notify_fail("�����װ˭��\n");
        write("�㿪ʹ��װ" + who->name() + "��\n");
//      message_vision("$N������һ�������Ƴɵ���Ƥ��ߡ�\n", this_player());
        this_player()->set_temp("apply/name", ({who->name()}));
	this_player()->set_temp("apply/id", ({who->id()}));
        this_player()->set_temp("apply/short", ({who->short()}));
        this_player()->set_temp("apply/long", ({who->long()}));
        return 1;
}
