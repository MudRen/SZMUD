//Code by Scatter
//V 1.0
//����޸��ߣ�Piao  2001/10/30
//�޸����ݣ�maxneili  and maxjingli�ļ��㹫ʽ  

//SCATTER �ٴθİ�
//��ǿ�� V. 2.01

//lisser ������ӹ���
//drug busy time
//myexp sort

#include <ansi.h>
inherit NPC;

int ask_neili();
int ask_jingli();
int ask_level();
int drug_busy();
int ask_exp();
mapping drug_list = ([
	"hot_drug" : "��ϵҩ�ﷴӦ",
	"bonze_drug" : "��ϵҩ�ﷴӦ",
	"cool_drug" : "��ϵҩ�ﷴӦ",
]);
string *drug_name = ({
	"��ϵҩ��",
	"����ҩ��",
	"��ϵҩ��",
});
void create()
{
        set_name(HIW"�޲�֪"NOR, ({
                "Wu Buzhi",
                "wu",
                "buzhi",
        }));

        set("title", "Ȫ���������ʦ");
        set("long",
"
��ʶ����Ȼ��������֮ƽ��
��ʶ������컯��ƽ����˽
��ʶ�����������
��ʶ�˾��Ե���ʵ֮��
��ʶ�����ﲻ�ܸ��Ŷ��Զ�
������ʶ����߾�����\n"
        );

        set("gender", "����");
        set("attitude", "peaceful");

        set("age", 50);
        set("shen_type",1);

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 10000);
        set("max_jing", 10000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("combat_exp", 1000000);
	set("inquiry", ([
		"maxlvl" : (: ask_level :),
		"maxneili" : (: ask_neili :),
		"maxjingli" : (: ask_jingli :),
		"drugbusy" : (: drug_busy :),
		"myexp" : (: ask_exp :),
        ]));

        set("score", 100);

switch( random(5) )
   {
        case 0:  // GUMU NPC (WITH WEAPON)
			set_skill("force", 300);
			set_skill("yunu-xinjing", 300);
			set_skill("dodge", 300);
			set_skill("feiyan-gong", 300);
			set_skill("bee-training", 300);
			set_skill("sword",300);
			set_skill("xuantie-jian",300);
			set_skill("parry", 300);
	
			map_skill("force", "yunu-xinjing");
			map_skill("dodge", "feiyan-gong");
			map_skill("parry", "xuantie-jian");
	        map_skill("sword", "xuantie-jian");

			set("nickname", "��Ĺ����");

			setup();
			carry_object("/clone/weapon/zhujian")->wield();
		break;
		case 1: // WUDANG NPC (WITHOUT WEAPON)
			set_skill("force", 300);
			set_skill("taiji-shengong", 300);
			set_skill("dodge", 300);
			set_skill("tiyunzong", 300);
			set_skill("cuff", 300);
			set_skill("strike", 300);
			set_skill("mian-zhang",300);
			set_skill("parry", 300);
			set_skill("sword", 300);
			set_skill("taiji-jian", 300);
			set_skill("literate", 300);
			set_skill("taoism", 300);

			map_skill("force", "taiji-shengong");
			map_skill("dodge", "tiyunzong");
			map_skill("strike", "mian-zhang");
			map_skill("parry", "taiji-quan");
			map_skill("cuff", "taiji-quan");

			map_skill("sword", "taiji-jian");
			
			prepare_skill("strike", "mian-zhang");
			prepare_skill("cuff", "taiji-quan");

			set("nickname", "�䵱����");

			setup();
		break;
		case 2: // GAIBANG NPC (WITHOUT WEAPON)
			set_skill("force", 300); 
			set_skill("huntian-qigong", 300); 
			 set_skill("strike", 300); 
			set_skill("xianglong-zhang", 300); 
			set_skill("hand", 300); 
			set_skill("shexing-diaoshou", 300); 
			set_skill("dodge", 300); 
		   set_skill("xiaoyaoyou", 300); 
			set_skill("parry", 300); 
			set_skill("blade", 300); 
			set_skill("liuhe-dao", 300); 
			 set_skill("begging", 300); 
		    set_skill("checking", 300);
        
		    map_skill("force", "huntian-qigong");
		   map_skill("strike","xianglong-zhang");
		   map_skill("hand",  "shexing-diaoshou");
		   map_skill("blade", "liuhe-dao");
		   map_skill("dodge", "xiaoyaoyou");
		   map_skill("parry", "xianglong-zhang");
        
		  prepare_skill("strike", "xianglong-zhang");

		  	set("nickname", "ؤ�����");

			setup();

		break;
		case 3:  // GUMU NPC (WITH WEAPON)
			set_skill("force", 300);
			set_skill("yunu-xinjing", 300);
			set_skill("dodge", 300);
			set_skill("feiyan-gong", 300);
			set_skill("bee-training", 300);
			set_skill("sword",300);
			set_skill("xuantie-jian",300);
			set_skill("parry", 300);
	
			map_skill("force", "yunu-xinjing");
			map_skill("dodge", "feiyan-gong");
			map_skill("parry", "xuantie-jian");
	        map_skill("sword", "xuantie-jian");

			set("nickname", "��Ĺ����");

			setup();
			carry_object("/clone/weapon/zhujian")->wield();
		break;
		case 4: // WUDANG NPC (WITHOUT WEAPON)
			set_skill("force", 300);
			set_skill("taiji-shengong", 300);
			set_skill("dodge", 300);
			set_skill("tiyunzong", 300);
			set_skill("cuff", 300);
			set_skill("strike", 300);
			set_skill("mian-zhang",300);
			set_skill("parry", 300);
			set_skill("sword", 300);
			set_skill("taiji-jian", 300);
			set_skill("literate", 300);
			set_skill("taoism", 300);

			map_skill("force", "taiji-shengong");
			map_skill("dodge", "tiyunzong");
			map_skill("strike", "mian-zhang");
			map_skill("parry", "taiji-quan");
			map_skill("cuff", "taiji-quan");

			map_skill("sword", "taiji-jian");
			
			prepare_skill("strike", "mian-zhang");
			prepare_skill("cuff", "taiji-quan");

			set("nickname", "�䵱����");

			setup();
		break;
		case 5: // GAIBANG NPC (WITHOUT WEAPON)
			set_skill("force", 300); 
			set_skill("huntian-qigong", 300); 
			 set_skill("strike", 300); 
			set_skill("xianglong-zhang", 300); 
			set_skill("hand", 300); 
			set_skill("shexing-diaoshou", 300); 
			set_skill("dodge", 300); 
		   set_skill("xiaoyaoyou", 300); 
			set_skill("parry", 300); 
			set_skill("blade", 300); 
			set_skill("liuhe-dao", 300); 
			 set_skill("begging", 300); 
		    set_skill("checking", 300);
        
		    map_skill("force", "huntian-qigong");
		   map_skill("strike","xianglong-zhang");
		   map_skill("hand",  "shexing-diaoshou");
		   map_skill("blade", "liuhe-dao");
		   map_skill("dodge", "xiaoyaoyou");
		   map_skill("parry", "xianglong-zhang");
        
		  prepare_skill("strike", "xianglong-zhang");

		  	set("nickname", "ؤ�����");

			setup();

		break;
}

		

}


//> ����ʦ������(Buwu)��ֱ���� /d/city/npc/wubuzhi.c �İɡ�
//����ʦ������(Buwu)��(skills-1)^3 = exp
// (X - 1)^3 = EXP
//
int ask_level()
{
	int comexp, answer, i;
	object me = this_player();
	
	comexp = me->query("combat_exp");
/*
	comexp = comexp * 10;
	for(i=0;comexp>i*i*i;i++)
	
	answer = i + 1;
*/
        answer = me->max_skill(comexp);
	
	tell_object(me, "�޲�֪˵������Ŀǰ����ߵȼ�������"+ HIG + chinese_number(answer) + NOR +"��\n");
	return 1;
}


int ask_neili()
{
	int jifaforce, answer, xtgg;
	object me = this_player();
	
	jifaforce = me->query_skill("force");
	xtgg = me->query("con");
	
	answer = jifaforce * xtgg * 2 / 3;
	
	tell_object(me,"�޲�֪˵������Ŀǰ�����������"+ HIG + chinese_number(answer) + NOR +"��\n");
        return 1;
}

int ask_jingli()
{
	int jifaforce, answer, xtgg;
	object me = this_player();
	
	jifaforce = me->query_skill("force");
	xtgg = me->query("con");
	answer = jifaforce * xtgg /2;
	
	tell_object(me,"�޲�֪˵������Ŀǰ���������"+ HIG + chinese_number(answer) + NOR +"��\n");
	return 1;
}

int drug_busy()
{
	object me = this_player();
	string answer, *con, zi;
	int i, j, x;
	int cnt = 0;
	
	answer = "";
	con = keys(drug_list);
	for (i=0; i<sizeof(con); i++){	
		if (me->query_condition(con[i])){
			j = me->query_condition(con[i]);
                        answer += drug_name[i] + "��" + chinese_number(j / 2 ) + "����\n";
			cnt++;
			}
		}

	if (cnt == 0)
                tell_object(me,"�޲�֪˵����������û�з���ҩ�\n");
	else{
		zi = (cnt==1)?"���У�\n":"�ֱ��У�\n";
                tell_object(me,"�޲�֪˵������Ŀǰ����"+ chinese_number(cnt) +"�������ҩ����´��ٷ��õ�ʱ��" + zi + answer );
	}
        return 1;
}

int ask_exp()
{
	object where,ob,obj,*ob_list;
	string msg, name;
	int i, exp, top;

	ob_list = users();
	top = 1;
	exp = this_player()->query("combat_exp");
	if (wizardp(this_player()))
	{
		tell_object(this_player(),"�޲�֪˵�����������ɻ�Ҫʲô������\n");
		return 1;
		}
	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("combat_exp") > exp
		&& where
		&& !wizardp(ob_list[i])
		&& strsrch(file_name(where), "/d/") >= 0 )
			top++;
	}
	tell_object(this_player(),"�޲�֪˵����������������ʱ���ڵ�"+ chinese_number(top) +"λ��\n");
	return 1;
}
