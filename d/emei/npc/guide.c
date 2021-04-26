// Code of ShenZhou
// 15th-Sep-2000: yasuko
#include <ansi.h>
inherit NPC;

string ask_job_begin();
string ask_job_finish();

void create()
{
        int i;
        i=random(2);
        set_name("�׼ҵ���", ({ "sujia dizi", "guide"}));
        if (i==0) {
	        set("long", 
		        "����һ���������׼�Ů���ӡ�\n"
		"ֻ�����������ģ�һ��������������ӡ�\n");
        	set("gender", "Ů��");
        }
        if (i==1) {
	        set("long", 
		        "����һ���������׼��е��ӡ�\n"
		"ȴ����ü��Ŀ�㣬��ֹ����˹�ġ�\n");
        	set("gender", "����");
        }
        set("age", 14);
	set("attitude", "peaceful");

   	set("str", 30);
	set("int", 30);
  	set("con", 30);
	set("dex", 30);
	set("kar", 20);
	set("per", 20);
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("combat_exp", 0);
	set("inquiry", ([
	    "����" : (: ask_job_begin :),
	    "����" : (: ask_job_finish :),
	]));
        i=this_player()->query("family/generation");
        create_family("������", i, "����");
	setup();
	carry_object("/d/emei/npc/obj/hui-cloth")->wear();
}
