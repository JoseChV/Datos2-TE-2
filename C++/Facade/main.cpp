#include <iostream>
using namespace std;
class MisDepartment
{
  public:
    void submitNetworkRequest()
    {
        _state = 0;
    }
    bool checkOnStatus()
    {
        _state++;
        if (_state == Complete)
          return 1;
        return 0;
    }
  private:
    enum States
    {
        Received, DenyAllKnowledge, ReferClientToFacilities,
          FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
          ElectricianDidItWrong, DispatchTechnician, SignedOff, DoesNotWork,
          FixElectriciansWiring, Complete
    };
    int _state;
};

class ElectricianUnion
{
  public:
    void submitNetworkRequest()
    {
        _state = 0;
    }
    bool checkOnStatus()
    {
        _state++;
        if (_state == Complete)
          return 1;
        return 0;
    }
  private:
    enum States
    {
        Received, RejectTheForm, SizeTheJob, SmokeAndJokeBreak,
          WaitForAuthorization, DoTheWrongJob, BlameTheEngineer, WaitToPunchOut,
          DoHalfAJob, ComplainToEngineer, GetClarification, CompleteTheJob,
          TurnInThePaperwork, Complete
    };
    int _state;
};

class FacilitiesDepartment
{
  public:
    void submitNetworkRequest()
    {
        _state = 0;
    }
    bool checkOnStatus()
    {
        _state++;
        if (_state == Complete)
          return 1;
        return 0;
    }
  private:
    enum States
    {
        Received, AssignToEngineer, EngineerResearches, RequestIsNotPossible,
          EngineerLeavesCompany, AssignToNewEngineer, NewEngineerResearches,
          ReassignEngineer, EngineerReturns, EngineerResearchesAgain,
          EngineerFillsOutPaperWork, Complete
    };
    int _state;
};

class FacilitiesFacade
{
  public:
    FacilitiesFacade()
    {
        _count = 0;
    }
    void submitNetworkRequest()
    {
        _state = 0;
    }
    bool checkOnStatus()
    {
        _count++;
        /* Se recibe una solicitud de trabajo */
        if (_state == Received)
        {
            _state++;
            /* Se pasa el trabajo a un ingeniero */
            _engineer.submitNetworkRequest();
            cout << "Subido al ingeniero - " << _count <<
              " Llamadas telefónicas" << endl;
        }
        else if (_state == SubmitToEngineer)
        {
            /* Si el ingeniero completa el trabajo, se pasa a un eléctrico */
            if (_engineer.checkOnStatus())
            {
                _state++;
                _electrician.submitNetworkRequest();
                cout << "subida al eléctrico - " << _count <<
                  " llamadas telefónicas" << endl;
            }
        }
        else if (_state == SubmitToElectrician)
        {
            /* Si el eléctrico termina, sigue el técnico */
            if (_electrician.checkOnStatus())
            {
                _state++;
                _technician.submitNetworkRequest();
                cout << "subida al técnico - " << _count <<
                  " llamadas telefónicas" << endl;
            }
        }
        else if (_state == SubmitToTechnician)
        {
            /* Si el técnico termina, el trabajo se completo */
            if (_technician.checkOnStatus())
              return 1;
        }
        /* El trabajo no está completo*/
        return 0;
    }
    int getNumberOfCalls()

    {
        return _count;
    }
  private:
    enum States
    {
        Received, SubmitToEngineer, SubmitToElectrician, SubmitToTechnician
    };
    int _state;
    int _count;
    FacilitiesDepartment _engineer;
    ElectricianUnion _electrician;
    MisDepartment _technician;
};

int main()
{
  FacilitiesFacade facilities;

  facilities.submitNetworkRequest();
  /* Keep checking until job is complete */
  while (!facilities.checkOnStatus())
    ;
  cout << "El trabajo se completo despues de " << facilities.getNumberOfCalls() <<
    " Llamadas telefónicas" << endl;
  cout << "Ejemplo tomado de: https://sourcemaking.com/design_patterns/facade/cpp/1"<< endl;
}