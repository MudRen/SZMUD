// Code of ShenZhou
// /kungfu/class/emei/pers_job.h
// yasuko: 2000/09/13
#include <ansi.h>

string* place = ({
        "/d/city/kedian",
        "/d/dali/dlkd1",
        "/d/hangzhou/kedian",
        "/d/qilian/kedian",
        "/d/quanzhou/qzkedian",
        "/d/shaolin/kedian1",
        "/d/xixia/kedian",
//        "/d/xiangyang/kedian",
//        "/d/beijing/kedian",
});

string* area = ({
        "����",
        "����",
        "����",
        "����",
        "Ȫ��",
        "����",
        "����",
//        "����",
//        "����",
});

string ask_for_job()
{
        object ob,obj,me=this_player();
        int i;
        string meet_room,room;
        if (me->query("family/family_name")!="������") {
                command ("smile ");
                return RANK_D->query_respect(this_player())+"Ҳ��Ȱ����";
        }
        if (me->query_condition("get_pers_job") &&!me->query("last_finished")) {
                command ("hmm ");
                return "�ϻؽ����������û�����......";
        }
        if (me->query_condition("get_pers_job") &&me->query("last_finished")) {
                command ("hehehe ");
                return "�й���ʦ�ĸ����������̫ͦƽ�ġ�";
        }
        command ("nod ");
        i=random(sizeof(place));
        meet_room=place[i];
        if (me->query("id")=="yasuko") tell_object(me,sprintf("i:%d, area:%s, place:%s \n",i,area[i],meet_room));
//        if (!obj=find_object(meet_room)) 
        obj=load_object(meet_room);
        room=obj->query("short");
        ob=new("/d/emei/npc/guide");
        ob->move(obj);
        return "�ðɣ��Ǿ��ෳ"+RANK_D->query_respect(this_player())+"��ȥ"+area[i]+"��"+room+"���Ƕ���ͬ�ŵ������Ӧ�ء�";
}
