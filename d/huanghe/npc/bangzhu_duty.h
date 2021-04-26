// Code of ShenZhou
// /d/huanghe/npc/bangzhu_duty.h
// by aln 2 / 98

// duty 1   to accept players

int ask_join()
{
        object ob = this_player(), obj;
        string myfam, ob_fam;
        int exp = ob->query("combat_exp");

        ob_fam = (string)ob->query("family/family_name");
/*
        if( ob_fam == "ؤ��" ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(ob) + "һ����ؤ�������Ե׵İɣ�\n");
                return 1;
        }

        if( ob_fam == "����μ�" ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(ob) + "һ���Ǵ���������Ե׵İɣ�\n");
                return 1;
        }

        if( ob_fam == "�䵱��"
        ||  ob_fam == "������"
        ||  ob_fam == "��ɽ��"
        ||  ob_fam == "������" ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(ob) + "һ�����������������Ե׵İɣ�\n");
                return 1;
        }
*/
        myfam = (string)query("fam");
        if( (string)ob->query_temp("bangs/fam") == myfam ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(ob) + "�����ҿ���������Ц������\n");
                return 1;
        }

        if( exp > query("combat_exp") ) {
                say(name() + "˫��һ��ȭ����" + RANK_D->query_respect(ob) + "�书����˸�ǿ��Ī���ǿ��ҵ���Ц�ɡ�\n");

                return 1;
        }

        if( time() < (int)ob->query("bangs/jointime") + 600 ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(ob) + "������˷����޳����������ڽ���������\n");
                return 1;
        }

        message_vision("$N���ص�����һ��$n�ļ�򣬺ȵ��������ģ��ӽ��Ժ���ֵ�������ͬ����\n", this_object(), ob);

        ob->set_temp("apply/short",
                ({ HIR + myfam + "����"NOR + ob->query("name")+"("+capitalize(ob->query("id"))+")" }));
        ob->delete_temp("bangs");
        ob->delete("bangs");
        ob->set_temp("bangs/fam", myfam);
        ob->set("bangs/jointime", time());

        if( obj = present("bang ling", ob) )
                destruct(obj);

        obj = new(BANGLING);
        obj->set("owner", ob->query("id"));
        obj->set("fam", myfam);
        obj->set("combat_exp", query("combat_exp"));
        obj->set("long",
"����" + myfam + "�İ��������š�" + ob->query("name") + "����\n");
        obj->move(ob);
        message_vision("$N��һ" + obj->query("unit") + obj->name() + "�Ӹ�$n��\n", this_object(), ob);

        log_file("BangJoin", sprintf("%s��%sʱ����%s\n", ob->query("name"), ctime(time()), myfam));
        return 1;
}

// duty 2  assign jobs

string ask_job()
{
        object me = this_player(), leader, ling, ob, *obj, dest, room,obtemp;
        string myfam, *files, file, region, biaoju, ob_bang,place;
        int i, temp, myexp,n,sz,highprice,lowprice,tim;
        string *mydests, mydest, *starts;
        mapping job, destine;

        string *levels = ({
                "3000",
                "5000",
               "10000",
               "20000",
               "50000",
              "100000",
              "200000",
     	});

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

        if( objectp(leader = me->query_leader()) ) {
                if( leader != this_object() )
                         return RANK_D->query_rude(me) + "�����˰ﲻ�����������ˣ���";
        }

        if( !(ling = present("bang ling", me)) ) {
                ling = new(BANGLING);
                ling->set("owner", me->query("id"));
                ling->set("fam", myfam);
                ling->set("combat_exp", query("combat_exp"));
                ling->move(me);
                message_vision("$N��һ" + ling->query("unit") + ling->name() + "�Ӹ�$n��\n", this_object(), me);
        }

        if( time() < (int)me->query("bangs/asktime") + 60 ) {
                if( mapp(ling->query("job")) )
                        return RANK_D->query_rude(me) + "���Ǹ��ʹ�����";
        }

        me->set("bangs/asktime", time());

        myexp = (int)me->query("combat_exp");
        myexp = (4 * myexp + random(2 * myexp)) / 5;

        temp = sizeof(levels);
        for( i = temp-1; i >= 0; i-- ) 
                if( myexp >= atoi(levels[i]) ) break;

        if( i < 0 )
                return "���û���ʺ���İ���";

        job = (BANGJOB + levels[i])->query_job();

        if( mapp(ling->query("job")) )
                ling->delete("job");
        ling->set("job", job);

        if( ob = present("caili", me) )
                destruct(ob);

        switch(job["type"]) {
        case "Ѱ":
                command("nod");
                ling->set("job/max", atoi(levels[i]));
                return "��ȥ��" + job["name"] + "������";
                break;

        case "ɱ":
                command("nod");
                ling->set("job/max", atoi(levels[i]));
                return "��ȥ��" + job["area"] + "��" + job["name"] + "ɱ�ˡ�";
                break;

        case "̯��":
                command("nod");
                job = info_store[random(sizeof(info_store))];
                ling->set("job/name", job["name"]);
                ling->set("job/boss", job["boss"]);
                ling->set("job/place", job["place"]);
                ling->set("job/is_kill",0);
                me->delete("job/killer");
                return  job["name"] + "����»�û�н�̯�ѣ���ȥҪ(collect)����";
                break;

        case "����":
                obj = filter_array(children(BIAOTOU), (: clonep :));
                if( sizeof(obj) < 10 ) {
                        ob = new(BIAOTOU);
                        file = biao_places[random(sizeof(biao_places))];
                        ob->move(file);
                        dest = environment(ob);            
                        message("vision",
                        ob->name() + "Ѻ���ڳ����˹�����\n",
                        dest, ({ob}));
                        region = explode(file, "/")[1];
                        ling->set("job/name", ob->query("nickname"));
                        return "ȥ���̵ĵ����ǻ�������" + 
                        ob->query("nickname") + 
                        "���ڳ�������" + 
                        region_names[region] + dest->query("short") + "��";
                } else {
                        ob = obj[random(sizeof(obj))];
                        dest = environment(ob);
                        biaoju = (string)ob->query("nickname");

                        if( !dest || !biaoju ) {
                                destruct(ob);
                                command("shake");
                                return "��Ъ�Űɣ����û��Ҫ���İ���";
                        }

                        file = base_name(dest);
                        if( strsrch(file, "/d/") != 0
                        || !mapp(dest->query("exits")) ) {
                                destruct(ob);
                                command("shake");
                                return "��Ъ�Űɣ����û��Ҫ���İ���";
                        }

                        command("nod");
                        region = explode(file, "/")[1];
                        ling->set("job/name", biaoju);
                        return "ȥ���̵ĵ����ǻ�������" + biaoju + 
                        "���ڳ�������" + 
                        region_names[region] + dest->query("short") + "��";
                }
                break;

        case "ʾ��":
                obj = filter_array(children(BANGZHONG), (: clonep :));
                if( sizeof(obj) ) {
                obj = filter_array(obj, "is_victim", this_object(), myfam);
                if( sizeof(obj) ) {
                        sz=sizeof(obj);ob=obj[0];
                        if (me->query("combat_exp")>100000)
                        {      	for (n=1;n<sz;n++)
                        	{obtemp=obj[n];
                         	if (obtemp->query("combat_exp") > ob->query("combat_exp"))
                         		ob=obtemp;
                        	}
                        }else
                        {	for (n=1;n<sz;n++)
                        	{obtemp=obj[n];
                         	if (obtemp->query("combat_exp") < ob->query("combat_exp"))
                         		ob=obtemp;
                        	}
                        }
                        command("nod");
                        ob_bang = (string)ob->query("title");
                        me->set_temp("bangs/victim", ob_bang);
                        ling->set("job/name", ob_bang);
                        return "���" + ob_bang + "���������ǹ���ȥ����ȥɱһ��ʾʾ����";
                }
                }
                break;

        case "����":
                command("nod");

                job = info_guest[random(sizeof(info_guest))];
                region = explode(job["file"], "/")[1];

                ob = new(CAILI);
                ob->set("job", job);
                ob->set("owner", me);
                ling->set("job/title", job["title"]);
                ling->set("job/area", job["area"]);
                ob->set("long",
"����һ��" + myfam + "�����͸�" + "��" + job["title"] + "��" + "�Ĳ���\n");
                ob->move(me);
                message_vision("$N��һ" + ob->query("unit") + ob->name() + "����$n��\n", this_object(), me);
                message_vision(CYN"$N��$n˵���������ݲ����͸�(visit)" + job["area"] + "��" + "��" + job["title"] + "��" + "��\n"NOR,this_object(),me);
                return "���˲��¿���ʮ��Σ�գ��������;���ò����˾ͷ���(giveup)��������������";
                                
                break;

        case "����":
                region = explode(base_name(environment()), "/")[1];
                starts = keys(info_destine);
                if( member_array(region, starts) == -1 ) {
                        command("shake");
                        return "��Ъ�Űɣ����û��Ҫ���İ���";
                }
                destine = info_destine[region];
                mydests = keys(destine);
                mydest = mydests[random(sizeof(mydests))];
                ling->set("job/dest", region_names[mydest]);
                ling->set("job/bonus", destine[mydest]);
                ob = new(BANGZHU2);
                ob->set("name", query("name"));
                ob->set("fam",  myfam);
                ob->set("title", myfam + "����");
                ob->set("dest", mydest);
                ob->set_leader(me);
                ob->set("helper", me);
                command("nod");
                call_out("do_start", 1, this_object(), ob);
                return "˵������������岻�ʣ��㻤������" + region_names[mydest] + "��\n";
        }

        command("shake");
        return "��Ъ�Űɣ����û��Ҫ���İ���";
}

void do_start(object me, object ob)
{
        ob->move(environment());
        destruct(this_object());
}

// duty 3  accept stuffs

int accept_object(object who, object ob)
{
        object obj;
        int bonus, record;
        string name, chname = "";
        mapping job;

        if( who->query_temp("bangs/fam") != query("fam") ) 
                return notify_fail(name() + "��ŭ�����󵨣���ı��������������\n");

        if( !(obj = present("bang ling", who)) )
                return notify_fail(name() + "��ŭ����û���õĶ������������㶪����\n");

        if( !mapp(job = obj->query("job")) )
                return notify_fail(name() + "��ŭ����û���õĶ��������Լ��İ��񶼼ǲ�ס����\n");

        switch(job["type"]) {
        case "Ѱ":
                name = ob->name();
                for(int i = 0; i < strlen(name); i++)
                        if(name[i] > 160 && name[i] < 255) 
                                chname += name[i..i];
                if( chname != job["name"] )
                        return notify_fail(name() + "��ŭ����û���õĶ��������Լ��İ��񶼼ǲ�ס����\n");
                bonus = job["bonus"]/5*4 + job["bonus"]/5*3;
                record = bonus*2 + random(bonus);
                log_file("BangJob", sprintf("%s��%sʱ�ҵ�%s��%s�����\n", who->query("name"), ctime(time()), chname, chinese_number(record)));
                break;

        case "����":
                if( base_name(ob) != BIAOHUO )
                        return notify_fail(name() + "��ŭ����û���õĶ�������һ֦�ڶ��㲻����\n");
                if( ob->query("my_killer") != who->query("id") )
                        return notify_fail(name() + "��ŭ��������������ľ������ã������������������㣡\n");
                bonus=35 + ( ob->query("combat_exp") - 100000 )/10000;
                record = bonus * 3 - random(bonus/2);
                log_file("BangJob", sprintf("%s��%sʱ���ڵ�%s�����\n", who->query("name"), ctime(time()),chinese_number(record)));
                break;  
        }

        command("nod");
        obj->delete("job");

        who->add("combat_exp", record);
        who->add("shen", -bonus);
        obj->add("score", bonus);
        message_vision(CYN"$N������$n��ͷ��˵�����ɵĺã�����Ŭ���Ժ����д�ĺô����㡣\n"NOR,this_object(),who);

        remove_call_out("store");
        call_out("store", 1, ob);
        return 1;
}

// duty 4  teach skills
string ask_skills()
{
        object ling, me = this_player();
        int amount;

        if( is_fighting() )
                return RANK_D->query_rude(me) + "Ϲ����û������æ�ţ���";

        if( (string)me->query_temp("bangs/fam") != (string)query("fam") )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

        if( !(ling = present("bang ling", me)) )
                return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

        if( (string)ling->query("owner") != me->query("id") )
                return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";

        if( (amount = (int)ling->query("score")) < 10 )
                return RANK_D->query_rude(me) + "�ټӰѾ��������Ż�ָ����һ�£�";

        if( amount > 100 ) {
                me->set_temp("bangs/skills_asked", 100);
                ling->add("score", -100);
        } else {
                me->set_temp("bangs/skills_asked", amount);
                ling->delete("score");
        }
        tell_object(me, "����룺�书��Ӣ�����֡�\n");
        return "�ðɡ�";
}

int do_xue(string arg)
{
        object me = this_player();
        string *sname;
        int i, amount, level, mylvl;

        if( !(amount = (int)me->query_temp("bangs/skills_asked")) ) {
                write("�㻹û�������ͬ���ء�\n");
                return 1;
        }

        if( is_fighting() ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(me) + "Ϲ����û������æ�ţ���");
                return 1;
        }

        if( !arg ) {
                sname = keys(query_skills());
                write("\n" + name() + "��ѧ���ļ��ܣ�\n\n");
                for(i = 0; i < sizeof(sname); i++)
                        write(to_chinese(sname[i]) + " (" + sname[i] + ")" + "\n");
                return 1;
        }

        if( (level = (int)query_skill(arg, 1)) < 1 ) {
                say(name() + "ҡ��ҡͷ��������ûѧ����\n");
                return 1;
        }

        mylvl = (int)me->query_skill(arg, 1);
        if( level < mylvl ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(me) + "��Ȼ���������ˡ�\n");
                return 1;
        }

        if( mylvl > 80 ) {
                say(name() + "ҡ��ҡͷ�������ȥ��������ʽ��ʦ���ܼ������" + to_chinese(arg) + "��\n");
                return 1;
        }

        if( (int)me->query("jing") + 10 < (int)me->query("max_jing") ) { 
                write("����Ъ����ɡ�\n");
                return 1;
        }

        me->set("jing", 10);
        me->improve_skill(arg, amount * me->query("int") / 3); 
        me->delete_temp("bangs/skills_asked");

        message_vision("$N��$n����йء�" + to_chinese(arg) + "�������ʡ�\n", me, this_object());
        tell_object(me, "�����˰�����ָ�����ԡ�" + to_chinese(arg) + "���ƺ���Щ�ĵá�\n");
        return 1;
}

void store(object ob)
{
        if(ob) destruct(ob);
}

private int is_victim(object ob, string arg)
{
        string fam;

        if( !stringp(fam = ob->query("title")) ) return 0;
        if( fam == arg ) return 0;

        return 1;
}
