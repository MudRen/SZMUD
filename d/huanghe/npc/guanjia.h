// Code of ShenZhou
// /d/huanghe/npc/guanjia.h
// by aln 2 / 98

string ask_job()
{
        object me = this_player(), leader, ling, ob, *obj, dest, room,obtemp;
        string myfam, *files, file, region, biaoju, ob_bang,place ,name;
        int i, temp, myexp,n,sz,highprice,lowprice,tim;
        mapping job;
        object npcroom;

        string *levels = ({
                   "0",
                "2000",
                "3500",
                "5000",
               "10000",
               "20000",
               "50000",
              "100000",
              "200000",
              "400000",
              "1000000",
              "2000000",
        });

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";  

        tim = 120 + me->query("combat_exp")/200000;
        
/*      û�е���buwu ��ʱ����  
	if( objectp(leader = me->query_leader()) ) {
                if( leader != this_object() )
                         return RANK_D->query_rude(me) + "�����˰ﻹ���Ķ�������ˣ���";
        }
*/

        if( !(ling = present("bang ling", me)) ) {
                ling = new(BANGLING);
                ling->set("owner", me->query("id"));
                ling->set("fam", myfam);
                ling->set("combat_exp", query("combat_exp"));
                ling->move(me);
                me->delete_temp("recovered");
                message_vision("$N��һ" + ling->query("unit") + ling->name() + "�Ӹ�$n��\n", this_object(), me);
        }

        myexp = (int)me->query("combat_exp");
        myexp = (4 * myexp + random(2 * myexp)) / 5;

        temp = sizeof(levels);
        if (myexp > 4000000)
                return "�����书�Ѿ���˸�ǿ,����������ͷ����Ѱ�����˰�.";

//      if (mapp(ling->query("job"))) 
        if( time() < (int)me->query("clb_busy_time") + BUSY_TIME )
                return RANK_D->query_rude(me) + "���Ǹ��ʹ�����";

        me->set("clb_busy_time", time());
        for( i = temp-1; i >= 0; i-- ) 
                if( myexp >= atoi(levels[i]) ) break;

        if( i < 0 )
                return "С�ֵܺ��޽�������,���ǲ���Ϊ�";
        
        job=ling->query("job");
        
        if ( mapp(job) )
        	if (job["type"]=="����")
        		if (ob=present(job["good"],me))
        			destruct(ob);        		
        
        job = (BANGJOB + levels[i])->query_job();

        if( mapp(ling->query("job")) )
                ling->delete("job");
        ling->set("job", job);

        if( ob = present("caili", me) )
                destruct(ob);
                
        name = (string)me->query("name");
                
        switch(job["type"]) {
        case "Ѱ":
                command("nod");
                ling->set("job/max", atoi(levels[i]));
                return name + "����ȥ��" + job["name"] + "������";
                break;

        case "ɱ":
                command("nod");
                ling->set("job/max", atoi(levels[i]));
                if( (job["where"]!="") && (job["where"]!="random"))    
                {
                npcroom=find_object(job["where"]);
                if (! npcroom)      npcroom=load_object(job["where"]);
                if (npcroom)   npcroom->reset();
                }
                return name + "����ȥ��" + job["area"] + "��" + job["name"] + "ɱ�ˡ�\n" + "�ǵ���ʬ���������Ұ��ӡ�ǣ�sign�������ý�������֪�����ǳ��ְ��������";
                break;

        case "̯��":
                command("nod");
                job = info_store[random(sizeof(info_store))];
                ling->set("job/name", job["name"]);
                ling->set("job/boss", job["boss"]);
                ling->set("job/place", job["place"]);
                ling->set("job/is_kill",0);
                me->delete("job/killer");
		if( (job["place"]!="") && (job["place"]!="random"))     
                { 
                	npcroom=find_object(job["place"]); 
                     	if (! npcroom)	npcroom=load_object(job["place"]); 
                     	if (npcroom)	npcroom->reset(); 
                } 
                return  name + "��" + ling->query("job/name") + "����»�û�н�̯�ѣ���ȥҪ(collect)����";
//                log_file("debug/clb2", sprintf("give %s qustion \n\t\tname : %s\n\t\tboss: %s \n\t\tplace : %s", me->query("id"), job["name"]+"  "+ling->query("name"), job["boss"] + "  " + ling->query("boss"), job["place"] + "  " + ling->query("place")));
                log_file("debug/clb2", me->query("id") + "######" + job["name"]+"  "+ling->query("name") + "#####" + job["boss"] + "  " + ling->query("boss") + "#####" + job["place"] + "  " + ling->query("place"));
                log_file("debug/clb2", "test\n");
                break;

        case "����":
                obj = filter_array(children(BIAOTOU), (: clonep :));
                if( sizeof(obj) < 10 ) {
                        ob = new(BIAOTOU);
                        ob->setskill(myexp);
                        file = biao_places[random(sizeof(biao_places))];
                        ob->move(file);
                        dest = environment(ob);            
                        message("vision",
                        ob->name() + "Ѻ���ڳ����˹�����\n",
                        dest, ({ob}));
                        region = explode(file, "/")[1];
                        ling->set("job/name", ob->query("nickname"));
                        return name + "��ȥ���̵ĵ����ǻ�������" + 
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
                                return name + "����Ъ�Űɣ����û��Ҫ���İ���";
                        }

                        file = base_name(dest);
                        if( strsrch(file, "/d/") != 0
                        || !mapp(dest->query("exits")) ) {
                                destruct(ob);
                                command("shake");
                                return name + "����Ъ�Űɣ����û��Ҫ���İ���";
                        }

                        command("nod");
                        region = explode(file, "/")[1];
                        ling->set("job/name", biaoju);
                        ob->setskill(myexp);
                        return name + "��ȥ���̵ĵ����ǻ�������" + biaoju + 
                        "���ڳ�������" + 
                        region_names[region] + dest->query("short") + "��";
                }
                break;

        case "ʾ��":
                obj = filter_array(children(BANGZHONG), (: clonep :));
                if( !sizeof(obj) ) {
                         command("shake");
                         return name + "����Ъ�Űɣ����û��ʲô���ɶ����ǲ�����";
                }
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
                        return name + "�����" + ob_bang + "���������ǹ���ȥ����ȥɱһ��ʾʾ����";
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
                message_vision(CYN"$N��$n˵���������ݲ����͸�(song)" + job["area"] + "��" + "��" + job["title"] + "��" + "��\n"NOR,this_object(),me);
		if( (job["file"]!="") && (job["file"]!="random"))     
                { 
                	npcroom=find_object(job["file"]); 
                     	if (! npcroom)	npcroom=load_object(job["file"]); 
                     	if (npcroom)	npcroom->reset(); 
                } 
                return "���˲��¿���ʮ��Σ�գ��������;���ò����˾ͷ���(giveup)��������������";
                log_file("debug/clb2", sprintf("give %s qustiong :\n\ttype: %s\n\tling info: %O\n\t job info: %O\n", me->query("id"), job["type"], ling->query_entire_dbase(), job));
                break;

        case "����":
                command("nod");
                files = get_dir(BANGGOOD);
                if( !sizeof(files) ) {
                         command("shake");
                         return name + "����Ъ�Űɣ����û��Ҫ���İ���";
                }
                file = BANGGOOD + files[random(sizeof(files))];
                ob = new(file);
                ob->move(me);
                message_vision("$N��һ" + ob->query("unit") + ob->name() + "����$n��\n", this_object(), me);
                place=info_business[random(sizeof(info_business))];
                ling->set("job/name", ob->name());
                ling->set("job/good", ob->query("id"));
                ling->set("job/place",place);
                return name + "�������" + ob->query("unit") + ob->name() + "��ȥ����(bargain),��ȡ�����ü�Ǯ��";
                break;

        case "���":
                command("nod");
                ling->set("job/name", "���");
                return name + "����ȥ�챦�󵱲�ɡ�";
                break;
        }

        command("shake");
        return name + "����Ъ�Űɣ����û��Ҫ���İ���";
}

void do_start(object me, object ob)
{
        ob->move(environment());
        destruct(this_object());
}

int accept_object(object who, object ob)
{
        object obj;
        int bonus, record;
        string name, chname = "";
        mapping job;
        int addscore;
        record=0;bonus=0;
        
        
        if( who->query_temp("bangs/fam") != query("fam") ) 
                return notify_fail(name() + "��ŭ�����󵨣���ı�����ܹܣ�����\n");

        if( !(obj = present("bang ling", who)) )
                return notify_fail(name() + "��ŭ����û���õĶ������������㶪����\n");

        if( !mapp(job = obj->query("job")) )
                return notify_fail(name() + "��ŭ����û���õĶ��������Լ��İ��񶼼ǲ�ס����\n");

        addscore=obj->query("score")/5000;
        if (addscore>30) addscore=30;
        
        switch(job["type"]) {
        case "Ѱ":
                name = ob->name();
                for(int i = 0; i < strlen(name); i++)
                        if(name[i] > 160 && name[i] < 255) 
                                chname += name[i..i];
                if( chname != job["name"] )
                        return notify_fail(name() + "��ŭ����û���õĶ��������Լ��İ��񶼼ǲ�ס����\n");
                bonus = job["bonus"]+ random(job["bonus"]);
                bonus = bonus + addscore;
                record = bonus*2 + random(bonus/2);
                log_file("BangJob", sprintf("%s��%sʱ�ҵ�%s��%s�����\n", who->query("name"), ctime(time()), chname, chinese_number(record)));
                break;

        case "����":
                if( base_name(ob) != BIAOHUO )
                        return notify_fail(name() + "��ŭ����û���õĶ�������һ֦�ڶ��㲻����\n");
                if( ob->query("my_killer") != who->query("id") )
                        return notify_fail(name() + "��ŭ��������������ľ������ã������������������㣡\n");
                bonus=50 - ( ob->query("combat_exp") - 100000 )/10000;
                bonus = bonus + addscore;
                record = bonus * 3 - random(bonus);
                log_file("BangJob", sprintf("%s��%sʱ���ڵ�%s�����\n", who->query("name"), ctime(time()),chinese_number(record)));
                break;  
        }

        if( record == 0 ) return notify_fail("����ʯ��ŭ����������������\n");
        command("nod");
        obj->delete("job");

        who->add("combat_exp", record);
        who->add("shen", -random(bonus/4));
        
        message_vision(CYN"$N������$n��ͷ��˵�����ɵĺã�����Ŭ���Ժ����д�ĺô����㡣\n"NOR,this_object(),who);
        write(HIW"����ι������õ�"+chinese_number(bonus)+"�㹦�͵㣬" + chinese_number(record)+ "�㾭��ֵ��\n"NOR);
        who->add("clbscore",bonus);

        remove_call_out("store");
        call_out("store", 1, ob);
        return 1;
}

void store(object ob)
{
        ob->move("/d/shenlong/cangku");
}

private int is_victim(object ob, string arg)
{
        string fam;

        if( !stringp(fam = ob->query("title")) ) return 0;
        if( fam == arg ) return 0;

        return 1;
}
