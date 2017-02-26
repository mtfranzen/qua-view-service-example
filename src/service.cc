#include <luciconnect/asio.h>
#include <luciconnect/luciconnect.h>

namespace Tutorial {
  class DistanceService : public luciconnect::quaview::Service {

  public:
    DistanceService(std::shared_ptr<luciconnect::Connection> connection) : luciconnect::quaview::Service(connection) {
    }

    std::string GetName() override {
      return "DistanceService";
    };

    std::string GetDescription() override {
      return "Computes the distance to a given point (x,y,z).";
    }

    std::string GetUnit() override {
      return "Metre";
    }

    json GetInputs() override {
      return {
        {"x", "number"},
        {"y", "number"},
        {"z", "number"}
      };
    }

    json GetConstraints() override {
      return {};
    }

    bool SupportsPointMode() override {
      return true;
    }

    std::vector<float> ComputeOnPoints(std::vector<luciconnect::vec3> scenario_triangles, std::vector<luciconnect::vec3> points, json inputs) override {
      std::vector<float> results;
      for (auto point : points) {
        float dx, dy, dz;
        dx = (point.x - inputs["x"].get<float>());
        dy = (point.y - inputs["y"].get<float>());
        dz = (point.z - inputs["z"].get<float>());
        float distance = sqrt(dx*dx+dy*dy+dz*dz);

        results.push_back(distance);
      }
      return results;
    }
  };
}

int main(int argc, char **argv) {
  std::shared_ptr<luciconnect::Connection> connection = std::make_shared<luciconnect::Connection>("localhost", 7654);
  Tutorial::DistanceService* service = new Tutorial::DistanceService(connection);
  service->Run();
}
